// Copyright 2023 Martin Chan
// 
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
// BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// Helper macros for the C preprocessor to process my YAML
// Rule generating macros

// The 11 big groups
// Leading underscore for names
#define _BLOCK_COMMENT    comment.block.bluespec
#define _PUNCTUATION      punctuation.bluespec

#define _NUMBER           constant.numeric.bluespec
#define _ACTION           constant.language.bluespec
#define _DONT_CARE        constant.language.bluespec
#define _VOID             constant.language.bluespec

#define _FUNCTION         entity.name.function.bluespec
#define _CLASS            entity.name.class.bluespec

#define _INVALID          invalid.bluespec
#define _DEPRECATED       invalid.deprecated.bluespec

#define _CONTROL          keyword.control.bluespec
#define _OPERATOR         keyword.operator.bluespec

// no markup

#define _DIRECTIVE        meta.preprocessor.bluespec  // Works fine for Java, but not yet BSV
#define _SHORT_ASSIGNMENT meta.assignment

#define _TYPE_PRIMITIVE   storage.type.bluespec

#define _STRING_DOUBLE    string.quoted.double.bluespec

#define _SYSTEM_FUNCTION  support.function.bluespec
#define _SUPPORT          support.class.bluespec

#define _VARIABLE         variable.bluespec
#define _ENUM             variable.other.constant.bluespec


// Can't do this because we can't generate multiple lines.
// #define RULE(_name, _match)\
//     - name: _name \
//       match: _match

// Grammar macros
// Invoke all these with parentheses around e.g. blah(IDENTIFIER_CHAR)blah
// The leading ?: on each guarantee these are non-capturing.
#define IDENTIFIER_CHAR ?:[\p{Alpha}\d\$_]
#define LOWER_IDENTIFIER (?:\b[\p{Lower}_](IDENTIFIER_CHAR)*)\b
#define UPPER_IDENTIFIER (?:\b[\p{Upper}_](IDENTIFIER_CHAR)*)\b
#define ANY_IDENTIFIER (IDENTIFIER_CHAR)+
#define ARRAY_INDEXING (\[.*\]\s*)*
#define TYPE ?:(UPPER_IDENTIFIER)(\s*#)?  // excellent building block
#define ENUM UPPER_IDENTIFIER  // exactly the same
#define DOT_ACCESS ((?<=\.\s*)(LOWER_IDENTIFIER))

#define SV_KEYWORDS \
    (?:alias|always|always_comb|always_ff|always_latch|and|assert|assert_strobe \
    |assign|assume|automatic|before|begin|end|bind|bins|binsof|bit|break|buf \
    |bufif0|bufif1|byte|casex|casez|cell|chandle|class|endclass\
    |clocking|endclocking|cmos|config|endconfig|const|constraint|context|continue\
    |cover|covergroup|endgroup|coverpoint|cross|deassign|default|defparam|design\
    |disable|dist|do|edge|event|expect|export|extends|extern|final\
    |first_match|force|foreach|forever|fork|forkjoin\
    |generate|endgenerate|genvar|highz0|highz1|iff|ifnone|ignore_bins\
    |illegal_bins|import|incdir|include|initial|inout|inside|instance\
    |int|integer|intersect|join|join_any|join_none\
    |large|liblist|library|local|localparam|logic|longint|macromodule\
    |matches|medium|modport|nand|negedge|new|nmos|nor\
    |noshowcancelled|not|notif0|notif1|null|or|output|package|endpackage\
    |packed|parameter|pmos|posedge|primitive|endprimitive|priority|program\
    |endprogram|property|endproperty|protected|pull0|pull1|pulldown|pullup\
    |pulsestyle_onevent|pulsestyle_ondetect|pure|rand|randc|randcase|randsequence\
    |rcmos|real|realtime|ref|reg|release|repeat|rnmos|rpmos|rtran\
    |rtranif0|rtranif1|scalared|sequence|endsequence|shortint|shortreal\
    |showcancelled|signed|small|solve|specify|endspecify|specparam|static\
    |string|strong0|strong1|super|supply0|supply1|table|endtable\
    |tagged|task|endtask|this|throughout|time|timeprecision|timeunit|tran\
    |tranif0|tranif1|tri|tri0|tri1|triand|trior|trireg|type\
    |union|unique|unsigned|use|var|vectored|virtual|void|wait|wait_order\
    |wand|weak0|weak1|while|wildcard|wire|with|within|wor|xnor|xor)
