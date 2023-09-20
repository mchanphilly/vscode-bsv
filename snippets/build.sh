#!/bin/bash
npx js-yaml bluespec.snippets.yaml > bluespec.snippets.json # & is to make the window exit quietly
# wsl cpp -x c -imacros macros.h bluespec.snippetsRaw.yaml > bluespec.snippets.yaml
