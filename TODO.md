# TODO

## Development Infrastructure

Unlikely to do much of this unless this project scales up substantially.

* In an ideal world, we should have automated testing with proper test cases. I currently just visually scan a few Bluespec files to see if there's anything that looks wrong. As we add new features, there are more spots where things can break, and quite inconspicuously.
* Set up some easy command or argument to test a particular token by highlighting it as `INVALID`, so it's more conspicuous when it shows up.
* Refactor the rules, or diagram it.

## Syntax Highlighting

- If the identifier names don't adhere to the casing convention (lowercase for variables especially), my extension has trouble understanding them as what they are. While it's nice to have a syntax highlighter in compliance with the language specification, it can be confusing to developers if the Bluespec compiler accepts their identifier but their code editor doesn't.
- There are some functions in the Standard Prelude that I haven't hard-coded into the Action Analysis engine. There's some risk of these being redefined.

## Semantic Highlighting

* It's difficult to deal with conditional compilation inside of a case statement (e.g., see RiscyOO's `src_Core/CPU/CsrFile.bsv`) because the engine "forgets" we're in a case statement if we're also in an `ifdef` chunk. Patched it by ignoring the middle.
* Remember and distinguish between instances of structs and interfaces. These both use `identifier` but have different implications for dot accesses. For structs, it's always a CF read.
* The syntax highlighter isn't yet advanced enough to support Action Analysis for implicit returns, so it may currently assume methods and functions are performing actions even if it can be deduced from the surrounding code that actions aren't taking place.

## Snippets

* There's no automatic indentation after a method signature. I would need to perform a check that the method signature is for a method definition, because a method signature may also happen in an interface definition, where we wouldn't want to indent.
* Need to stop default word completion from shadowing snippets. When I type `for`, the first tab is sometimes just to finish the `for` word, not the `for` snippet.

## Other Advanced Features

- See what "IntelliSense, hovers, and validators" mean.