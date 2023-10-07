# Markdown Test

The injection grammar allows us to do syntax highlighting in fenced code blocks in Markdown.

```bluespec
module mkExample(Example);
    Reg#(Bit#(4)) ex_reg <- mkRegU;

endmodule
```

## Another Section
And we can still write Markdown outside.

```bsv
module mkExample(Example);
    Reg#(Bit#(4)) ex_reg <- mkRegU;
    rule tick;
        let new_value = ex_reg + 4;
        ex_reg <= ex_reg + new_value;
    endrule
endmodule
```

But non-Bluespec should still be processed correctly.
```yaml
conditional: # rather abstract rule
  begin: (?x)
    (?<=
      (?:if                    |
      rule.*(LOWER_IDENTIFIER)
      )
    )
    (?:\s*\()
  end: (?x)
    (?:\))
  patterns:  # short-circuit from context
    - include: '#always'
    - include: '#dot_read_all'
    - include: '#tagged_tag'
    - name: _ENUM
      match: (?<!tagged\s+)(UPPER_IDENTIFIER)(?!\s+(LOWER_IDENTIFIER))
    - include: '#remainder'
    - include: '#catch_error'  # catch-all
```

## TODO
However, we still have some issues with autoclosed brackets inside of the code blocks.

Non-exhaustive list:
- Typing `<` in a Bluespec block, e.g., for `register <= new_val` still uses the autoclose policy of Markdown. So typing `<` will look like `<>`, and you'll need to manually delete the second one since `<` has autoclose in Markdown.
  - It can be fixed, but I expect excerpts to be mostly written in (working) `.bsv` files and then copied over into Markdown, so I don't think it's necessary to add this support for *writing* Bluespec in Markdown. This injection grammar is mostly for *reading* Bluespec in Markdown, e.g., for writing documents that include Bluespec examples.
  - To fix this, we would need to edit the extension and play with scopes or something. There's some documentation on the fix in the "Token types and embedded languages" section of the [VS Code Syntax Highlight Guide](https://code.visualstudio.com/api/language-extensions/syntax-highlight-guide).