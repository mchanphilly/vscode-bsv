// https://martinchan.org/projects/bluespec-lexer/sample/
import FIFO::*;

// Integer literals
Integer i1 = 125;
Integer i2 = -16;
Integer i3 = 'h48454a;
Integer i4 = 32'h48454a;
Integer i5 = 8'o255;
Integer i6 = 12'b101010;
Integer i7 = 32'h_FF_FF_FF_FF;

// Real literals
Real r1 = 1.2;
Real r2 = 0.6;
Real r3 = 2.4E10; // exponent can be e or E
Real r4 = 5e-3;
Real r5 = 325.761_452_e-10; // underscores are ignored
Real r6 = 9.2e+4;

// String literals
String easy_string = "abcd";
String string_with_escapes = "a\nb\nc";
// String octal_string = ??? (Manual is unclear what it means by \OOO or \xHH)

/*
block comments
work fine
*/

typedef Bit#(32) Word;

typedef enum {
    Good,
    Bad,
    Okay
} Status deriving (Eq);

typedef struct {
    Bit#(5) someIndex;
    Bool someBool;
} SomeItem deriving (Bits, Eq, FShow);

typedef union tagged {
    struct {Bit#(2) some_member; SomeItem item;} SubUnion1;
    struct {Bit#(4) some_other_member;} SubUnion2;
    Bit#(4) SubUnion3;
} SomeUnion;

// conditional compilation rendering (and similar directives)
`ifdef SOME_CONDITION
module mkConditionalModule(ConditionalModule);
    method Action do_something;
endmodule
`endif

`define example_macro Reg#(Bit#(8))

interface SomeBufferInterface;
    method ActionValue#(SomeItem) remove_item;  // removes and returns item from buffer
    method Action add_item(SomeItem item);  // adds item to buffer
endinterface

(* synthesize *)
module mkSomeBuffer(SomeBufferInterface);
    Counter counter <- mkCounter;  // doesn't necessarily need to be named counter
    Reg#(Bit#(5)) raw_counter <- mkReg(0);
    Reg#(Bit#(8)) r <- mkReg(?);  // don’t-care value; usually we would use mkRegU instead
    Reg#(Status) status <- mkReg(Good);
    Vector#(5, Bool) truths <- replicateM(mkReg(False));  // No highlighting for interior ActionValue
    
    function Action do_thing(Bit#(32) thing_input);
        action
            $display("Hex representation: %x", thing_input);
            $display("First half: %3x", thing_input[31:16]);

            if (thing_input == 16) begin
                $display("Halfway there!");
            end
        endaction
    endfunction

    function Action update_status(Status new_status, Status another_enum);
        action  // Looks silly, but I think the compiler demands it.
            noAction;  // toy example; looking for when we use this.
        endaction
    endfunction

    function Action do_other_thing;
        action
            $display("Smoke test");
        endaction
    endfunction

    (* conflict_free = "tick, check_raw" *)

    // etc. other state
    rule tick if (status != Good);
        counter.incr; 
        if (status == Bad && counter.status == Bad) status <= Good;

        // For unpacking structs
        match Status {
            someIndex: .someIndex,
            someBool: .someBool
        } = counter.get_some_item;

        // We assume there are no side effects in matching expressions.
        if (counter.dump matches tagged Valid .member &&&
            counter.id   matches tagged Valid .id) begin
            $display("This is for conditional matching");
        end
    endrule

    rule check_raw(raw_counter == ~0);  // Guard may have no `if`.
        $display("Something is wrong");
        $finish;
    endrule

    method ActionValue#(SomeItem) remove_item if (counter.value != 0);
        // We highlight based on whether there's a state change involved.
        let some_input = counter.value;            // Pure value method (no state change)
        let result = calculate_something(some_input);  // Pure function (no state change)
        raw_counter <= 0;                    // Non-blocking assignment (state change on left)
        let item <- some_removal_action;           // Defining operator (state change on right)
        // State change on both sides? I don't think it's a common design pattern, nor encouraged
        // by Bluespec language primitives
        truths[2] <= True;  // We can assign to indexed registers too.
        let some_output <- counter.some_actionvalue;  // We can do ActionValue methods

        // Different types of implied actions.
        counter.decr;               // (method)
        do_other_thing;             // (function)
        do_thing(counter.value);    // (function w/ args)
        update_status(Good, Bad);   // (w/ enum as args)

        case (status)
            Good: $display("Good!"); // No block is okay
            Okay: begin  // begin/end block is okay
                $display("Okay");
            end
            Bad: $finish;
        endcase

        let some_union = tagged SubUnion3 'b1010;  // alias of Bit#(4) in this example 
        // TODO figure out syntax for instantiating a tagged union
        // with multiple members (I haven't yet seen)
        case (some_union) matches
            tagged SubUnion1 {some_member: .sm, item: .i} :
                begin
                    let combo = do_combination(sm, i);  // not Action
                    $display(combo);
                    counter.check(combo);  // likely state change on counter
                end 
            tagged SubUnion2 {some_other_member: .some} :
                $display(some);
            tagged SubUnion3 .v : $display(v); 
        endcase

        return item;
    endmethod
    // etc. other methods/rules
    // TODO check other whitespace conventions work (no whitespace? a lot of it?)
endmodule

// Advanced features: highly modified (synthetic) snippets from the open-source RiscyOO/Toooba 
// https://github.com/bluespec/Toooba/blob/master/src_Core/RISCY_OOO/procs/lib/Scoreboard.bsv

// RTL import  (TODO might be a little iffy token-wise. It's a very different format from normal BSV)
import "BVI" ASSIGN1 =
module packReset#(Reset rst)(OutputBit);
   default_clock no_clock;
   default_reset no_reset;

   input_reset rst(IN) = rst;

   method OUT out reset_by(rst);

   schedule (out) CF (out);
endmodule

// Nested and parametric interfaces
interface InorderRenamingScoreboard#(
    numeric type setReadyNum, type t
);
    interface Vector#(SupSize, SbSetBusy) setBusy; // at rename
    interface Vector#(setReadyNum, Put#(PhyRIndx)) setReady;
    method Bit#(TLog#(TAdd#(size, 1))) search1(Maybe#(t) r);
endinterface

// Returning modules
function SbLookup getLookupIfc(Vector#(NumPhyReg, Bool) sbVec);
    for(Integer i = 0; i < valueof(setReadyNum); i = i+1) begin  // for loop
        if(True) noAction;
    end
    return (interface SbLookup;
        method RegsReady get(PhyRegs r) = unpack(0);
        method Action remove(Maybe#(PhyDst) r);
            sb.remove;  // This is an Action. (TODO support nested definition)
        endmethod
    endinterface);
endfunction

// Implied return values (TODO)
module mkPipelineScoreboard(Scoreboard#(size,t)) provisos (Bits#(t,tSz), Eq#(t));
    SFifo#(size, Maybe#(t), Maybe#(t)) f <- mkPipelineSFifo(isFound);
    interface lookup = map(getLookupIfc, genVector);  // implied return interface
    method insert = d.enq;  // implied return method
    function Integer lookup_port = get_something(setReadyNum); // TODO lexer assumes state change

    // Several consecutive indexes with functional or method accesses
    sb[valid_dst.indx][setBusy_port(i)][those.and_that(these[nested(42)])] <= True;
    something <= compare(arr[24]);
    state <= arr[20];
endmodule
