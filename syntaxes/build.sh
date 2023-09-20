#!/bin/bash
wsl cpp -x c -imacros macros.h bluespec.tmLanguageRaw.yaml > bluespec.tmLanguage.yaml
npx js-yaml bluespec.tmLanguage.yaml > bluespec.tmLanguage.json # & is to make the window exit quietly
