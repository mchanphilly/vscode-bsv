# Change Log

All notable changes to this will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html)

## [Unreleased]

## [1.1.0] - 2023.10.04

- Added injection support for Markdown. We can now do e.g., ` ```bluespec ` blocks in Markdown and have them be properly formatted with this extension.
- Fixed `==` to be recognized as a single operator instead of two `=`.
- Fixed `input` from being recognized as keyword even when part of a bigger identifier.
- Fixed (with stopgap) the `?` in ternary operator from being marked as a syntax error when at the end of a line. 
- (Invisible) Added some `meta` categories in anticipation of future refactor.

## [1.0.2] - 2023-09-21

- Minor cosmetic changes to README and packaging.

## [1.0.1] - 2023-09-21

- Minor cosmetic changes to README

## [1.0.0] - 2023-09-21
### Added

- Initial syntax highlighting
- Initial few snippets
- Initial promotional material
