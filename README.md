# Bluespec for VS Code

![Banner that says Bluespec SystemVerilog for VS Code, and a link to my website at https://martinchan.org/bsv/](/images/display_short_banner.png)

This extension for VS Code offers high-quality syntax highlighting for Bluespec and Minispec on par with syntax highlighting for mainstream languages.

No matter what you're using Bluespec for, whether it's research, education, or industry, this syntax highlighter is what you need to have a modern experience with Bluespec on VS Code.

Not affiliated with Bluespec Inc. Check out my other work at https://martinchan.org/.

## Features

> Examples below use excerpts of the MIT RiscyOO/Bluespec Toooba open-source project. 

### Sophisticated Highlighting

Developers have grown accustomed to the fantastic syntax highlighting available for mainstream languages like Python, C, Java, and TypeScript.

For the first time, high-quality syntax highlighting has now come to Bluespec for VS Code. 





The syntax highlighting has been thoroughly tested against the most complex Bluespec available and with a variety of programming styles.

Whether you're completing 6.191/6.192 labs for homework, conducting research on advanced computer architecture techniques, or building products for industry, this extension is for you.

If something's worth doing, it's worth doing right. I built this extension from the ground up with an intense eye for rigor and detail. Anything you can expect from a modern syntax highlighter[^semantic], you can expect from this extension.

[^semantic]: Except for cases where a language server is required. My extension simply has no backend for semantic highlighting right now.

Further, tokens have been carefully selected to be consistent with syntax highlighting standards across languages, allowing developers to bring in their general programming knowledge with them as they move to Bluespec. I researched syntax highlighting in languages like Python, C, Java, and TypeScript to make sure that my extension tokenizes similarly to theirs, e.g., things like Bluespec interfaces look like classes, or Bluespec enums look like other enums, and that these are treated differently.



### Action Analysis Engine

This syntax highlighter takes it one step further and distinguishes between actions and functional pieces of code.

With one glance, you can see what portions of your Bluespec are responsible for state change, and which ones are only performing computation. I also discuss the concepts underlying this [in a post about my Bluespec lexer for Rouge](https://martinchan.org/projects/bluespec-lexer/#actions-and-state-changes).







Be aware that whether a method performs an `Action` is only one part of scheduling. Read-only methods may also have scheduling implications, and you would need to take a deeper look into the compiler's outputted schedule to check.

Also be aware that the Action Analysis Engine operates purely off syntax with not much capability for state. If you're attempting to use implicit typing (which is supported by the compiler) for return values, my syntax highlighter isn't yet sophisticated enough to track that.

### Future Features

Currently, there isn't much other than syntax highlighting. In terms of the future, VS Code provides a significant number of [contribution points](https://code.visualstudio.com/api/references/contribution-points) that allow an extension developer to tremendously boost the productivity of their users.

If you find these possibilities exciting, let me know. The more interest there is, the more I would be inclined to add more features or fix issues. But it's probably going to be low priority for me until I find employment, and then only if I'm working in Bluespec.

#### Snippets

Yes! We're missing many snippets beyond `for` and `if`. Send me snippets you want that aren't already in the [Snippets README](https://github.com/mchanphilly/vscode-bsv/tree/main/syntaxes/snippets/). It's easier to add to a list than it is to implement since I haven't fully figured out how to implement them yet. Or submit a pull request if you're in a big old hurry, to either the list or the actual snippets.







#### Language Server

One thing I've been eyeing is using [Bluespec Compiler](https://github.com/B-Lang-org/bsc) internals with the VS Code [language server extension framework](https://code.visualstudio.com/api/language-extensions/language-server-extension-guide) to provide useful information to the developer even before compilation. Some information can come from language-agnostic quality of life improvements, like graying out for unused ``ifdef`s, seeing unused arguments or variables, or seeing where an instance was initially declared.

But more excitingly, it would also enable Bluespec-specific improvements, like distinguishing between method calls and struct accesses (a form of [semantic highlighting](https://code.visualstudio.com/api/language-extensions/semantic-highlight-guide)) or being able to see details about schedules, guards, and conflicts within the comfort of VS Code.

Can you imagine mousing over a module instance and being presented with its schedule? Or mousing over a method and being presented with (hopefully a human-readable version of) its guard? A developer could debug with conventionally post-compile information without ever needing to leave the editor.

## Background

If you're using Bluespec (or Minispec) for class, congratulations! I was first introduced to Bluespec through Daniel Sanchez's [Minispec](https://github.com/minispec-hdl/minispec/) when I took 6.004 (now 6.191) as a sophomore at MIT in Fall 2021. Then I really got into Bluespec when I took 6.192 my senior year in Spring 2023 with Arvind and the spectacular Thomas Bourgeat, who's now teaching at EPFL.

I made this extension because the syntax highlighting available for Bluespec on VS Code was [really bad](https://martinchan.org/projects/bluespec-lexer/#next-steps). I didn't even use VS Code for 6.004 because they had us doing old-fashioned command line business (gross), but I used VS Code for 6.192 and a [summer project afterward](https://martinchan.org/projects/processor/). The available syntax highlighting was one step above nothing, which is to say they only did keyword highlighting and VS Code-provided bracket matching.

I think I know why it took so long before someone came to market with a decent VS Code extension for Bluespec.

Right now, (according to Stack Overflow) [3 in 4 developers use VS Code](https://en.wikipedia.org/wiki/Visual_Studio_Code#Reception), just as it's been for the past 3 years. At MIT, the majority is so strong that 6.100 and 6.102, two of the three introductory programming classes, have now coalesced to recommending VS Code for students in need of code editors. When I took them not so long ago, 6.100 was recommending (of all things) Spyder, and 6.102 was recommending Eclipse. I don't know what 6.101 will recommend, since it's a spring class.

But as recent as 2016, [only 7% of developers used VS Code](https://insights.stackoverflow.com/survey/2016#technology-development-environments). The majority then were Notepad++ and Visual Studio each at (not mutually exclusive) 35%.[^hold] I would guess that most people working in Bluespec have done so for years and years, and they've probably gotten accustomed to whatever they're using, whether it's Vim, Emacs, or Notepad++.

I think if Bluespec wants to better appeal to people currently in college (or recently out of college), they should've built some tools for VS Code. But they didn't, so I did.

[^hold]: You can imagine how big a hold VS Code has now that its majority *for several years running* is more than what those two were combined.

## Feedback

I'm interested in hearing about syntax highlighting bugs, usability issues, and snippet and feature requests.

If you find something wrong with syntax highlighting, or something that would be improved, please also send me a sample of Bluespec that exhibits what you're seeing and a short description.

And if you enjoy using this extension, please drop a review or send me a message.

## See Also

- Check out my website at https://martinchan.org/
- If you use Jekyll for site generation and you want to put Bluespec excerpts on your website, check out my [Bluespec lexer](https://martinchan.org/projects/bluespec-lexer/) for Rouge, which is the syntax highlighting engine that Jekyll uses. I use it to render Bluespec excerpts on my website.

- If you're hiring or know someone who is, I'm currently looking for employment in computer architecture, software, or RTL. I'm a recent graduate of MIT in computer science and open to relocation.
  - If you work somewhere in the United States that uses Bluespec, please reach out regardless of whether you're hiring. I would like to hear from you.

## Known Issues

I'm unlikely to fix any issues or add any features unless I become employed (either in academia or industry) somewhere that uses Bluespec. Nevertheless, it's easier to track than it is to fix.

- The syntax highlighter isn't yet advanced enough to support Action Analysis for implicit returns, so it may currently assume methods and functions are performing actions even if it can be deduced from the surrounding code that actions aren't taking place.
- I'm not sure how to syntactically distinguish `?` the don't-care value with `?` the ternary operator yet. I need to come up with a good set of test cases.
- There's no automatic indentation after a method signature. I would need to perform a check that the method signature is for a method definition, because a method signature may also happen in an interface definition, where we wouldn't want to indent.
- Some issues with distinguishing between enums, interfaces, and structs in different contexts, especially nested conditionals. Should be a straightforward fix, as long as we come up with a decent list of test cases.
  - Some are intractable without a language server.
- It's difficult to deal with conditional compilation inside of a case statement (e.g., see RiscyOO's `src_Core/CPU/CsrFile.bsv`) because the engine "forgets" we're in a case statement if we're also in an `ifdef` chunk. Patched it by ignoring the middle.
- Some issues with shorthand assignment (e.g., using `function Type identifier = [blah blah blah];` instead of `function/endfunction` pairs.) not properly rendering interfaces.

## Release Notes

### 1.0.0

Initial release:

* Syntax highlighting.
* General extension packaging.
