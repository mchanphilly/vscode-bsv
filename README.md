# Bluespec for VS Code

![tiny_market](C:\Users\marti\Files\Projects\bluespec-vsc\bsv\images\tiny_market.png)

This extension for VS Code offers high-quality syntax highlighting for Bluespec and Minispec on par with syntax highlighting for mainstream languages.

Whether you're using Bluespec for research, industry, or education, this extension is for you.

## Features

> Examples below use excerpts of the MIT RiscyOO/Bluespec Toooba open-source project. 

### Sophisticated Highlighting

Developers have become accustomed to the fantastic syntax highlighting available for mainstream languages like Python, C, Java, and TypeScript on VS Code. It's about time that Bluespec developers have access to that too.





The syntax highlighting has been thoroughly tested against the most complex Bluespec available. No matter how complex your Bluespec, this syntax highlighter should be able to handle it.

Further, tokens have been carefully selected to be consistent with syntax highlighting standards across languages, allowing developers to bring in their general programming knowledge with them as they work in Bluespec.

### Action Analysis Engine

This syntax highlighter takes it one step further and distinguishes between actions and functional pieces of code.

You can easily pinpoint 

Be aware that whether a method performs an `Action` is only one part of scheduling. Read-only methods may also have scheduling implications, and you would need to take a deeper look into 

## Getting Started with Bluespec?

New to Bluespec? Check out the open-source Bluespec compiler





(Not affiliated with Bluespec Inc.)

## Known Issues

- The syntax highlighter isn't yet advanced enough to support Action Analysis for implicit returns, so it may currently assume methods and functions are performing actions even if the .



## New Issue?

I'm interested in hearing about syntax highlighting bugs, usability issues, and feature requests.

If you find something wrong with syntax highlighting, or something that would be improved, please send me a sample of Bluespec that exhibits what you're seeing and a short description.

## See Also

- Check out my website at https://martinchan.org/
- If you use Jekyll for site generation, check out my [Bluespec lexer](https://martinchan.org/projects/bluespec-lexer/) for Rouge, which is the syntax highlighting engine that Jekyll uses.
- If you're an employer, I'm currently looking for employment, preferably somewhere in computer architecture or RTL. If you're an employer that uses Bluespec, count me as doubly interested.

## Release Notes

### 1.0.0

Initial release:

- Syntax highlighting


---

## Working with Markdown

You can author your README using Visual Studio Code. Here are some useful editor keyboard shortcuts:

* Split the editor (`Cmd+\` on macOS or `Ctrl+\` on Windows and Linux).
* Toggle preview (`Shift+Cmd+V` on macOS or `Shift+Ctrl+V` on Windows and Linux).
* Press `Ctrl+Space` (Windows, Linux, macOS) to see a list of Markdown snippets.

## For more information

* [Visual Studio Code's Markdown Support](http://code.visualstudio.com/docs/languages/markdown)
* [Markdown Syntax Reference](https://help.github.com/articles/markdown-basics/)

**Enjoy!**
