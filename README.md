# Bluespec for VS Code

This extension for VS Code offers sophisticated syntax highlighting for Bluespec and Minispec on par with syntax highlighting for mainstream languages.

## Features

> Examples use excerpts of the MIT RiscyOO/Bluespec Toooba open-source project. 

### Sophisticated Highlighting

Developers have become accustomed to the fantastic syntax highlighting available for mainstream languages like Python, C, Java, and TypeScript. It's about time that Bluespec developers have access to that too.



The syntax highlighting has been thoroughly tested against the most complex Bluespec available.

Further, tokens have been carefully selected to be consistent with syntax highlighting standards across languages, allowing developers to bring in their general programming knowledge with them as they work in Bluespec. No matter what theme you use, writing and editing Bluespec code should be as smooth as writing any other programming language.



For instructors using Bluespec or Minispec as a pedagogical tool, your students need no longer  

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

If you find something wrong with syntax highlighting, or something that would be improved, please send me a sample of Bluespec that exhibits what you're seeing. If it's not self-explanatory, please also include a short description.

Also, I'm looking for employment.

## Release Notes

Users appreciate release notes as you update your extension.

### 1.0.0

Initial release:


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
