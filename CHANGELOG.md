# Change Log

All notable changes to this will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html)

## [Unreleased]

## [1.1.4] - 2024.02.05

### Changed
- Updated description

## [1.1.3] - 2023.10.07

### Fixed
- Fixed Markdown Bluespec injection overriding other injected languages. Adjusted test case to cover.
  - 1.1.1 and 1.1.2 were also meant to be this, but didn't end up working in production.
  - Used [Matt Bierner's useful example](https://github.com/mjbvz/vscode-fenced-code-block-grammar-injection-example) to do it properly.

## [1.1.0] - 2023.10.04

### Added
- Added injection support for Markdown. We can now do e.g., ` ```bluespec ` blocks in Markdown and have them be properly formatted with this extension.
- (Invisible) Added some `meta` categories in anticipation of future refactor.

### Fixed
- Fixed `==` to be recognized as a single operator instead of two `=`.
- Fixed `input` from being recognized as keyword even when part of a bigger identifier.
- Fixed (with stopgap) the `?` in ternary operator from being marked as a syntax error when at the end of a line. 

## [1.0.2] - 2023-09-21

- Minor cosmetic changes to README and packaging.

## [1.0.1] - 2023-09-21

- Minor cosmetic changes to README

## [1.0.0] - 2023-09-21
### Added

- Initial syntax highlighting
- Initial few snippets
- Initial promotional material
