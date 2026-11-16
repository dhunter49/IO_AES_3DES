This file is a summary of Qt recommendations and own rules

## Coding conventions:

- every var in a separate line,
- braces shall be started in the same line, except function implementation and class declarations (those shall start in a new line)
- braces shall not appear if conditional statement requires only one line, 
  - except when either if or else statement has more lines then both shall have braces
  - except when conditional statement requires more than one line
- parentheses should split statements (even if by math rules it's obvious what's first) ex. `(a && b) || c`
- lines should not exceed 100 chars - wrap if necessary
- operators on wraps should begin new line, rather than finish a line
- do not use `#pragma once`, but do include guards 
- avoid using C casts, prefer C++ ones
- `auto` should be used ONLY when there's repetition of type (ex. `auto something = new MyCustomType;` or when assigning iterator type

## Code

Naming:
- classes, structs, enums, type aliases: `PascalCase`
- functions, methods: `camelCase`
- local variables, function/method parameters: `camelCase`
- member variables (private/protected): `m_camelCase`
- static member variables: `s_camelCase`
- constants (`constexpr`, `const` globals, static constants): `kPascalCase`
- enum values (prefer `enum class`): `PascalCase`
- namespaces: `lowercase`
- template parameters: `PascalCase`
- acronyms are treated as words, only the first letter is capitalized
- names must not start with a digit, so `3DES` becomes  `TripleDes` 

Qt-specific:
- getters have no `get` prefix: `key()`, `blockSize()`
- setters use the `set` prefix: `setKey()`, `setMode()`
- boolean getters use `is` / `has` / `can`: `isValid()`, `hasKey()`

## Files and directories

- source/header files: `lowercase`, matching the class name
- docs files (.md, .tex) `under_scores`
- one main class per file pair
- module-wide export header: `<module>_global.h`
- header guards: `UPPER_SNAKE_CASE_H`
- directories: `lowercase`

## GUI (Qt Designer)

- widget `objectName`: `camelCase` with a type suffix (e.g. `encryptButton`, `keyLineEdit`, `resultsTableView`)
- `.ui` file name equals the class name in lowercase (e.g. `mainwindow.ui` for `MainWindow`)

## CMake

- target names: `lowercase` (e.g. `crypto`, `benchmark`, `report`, `cli`, `gui`)
- variables: `UPPER_SNAKE_CASE` (e.g. `PROJECT_SOURCES`)
- commands and functions: `lowercase` (e.g. `add_library`, `target_link_libraries`)
- compile definitions: `<MODULE>_LIBRARY` (e.g. `CRYPTO_LIBRARY`)

## Git and GitHub

- branches: `short-description` in `kebab-case`

Sources:
https://wiki.qt.io/Qt_Coding_Style
https://wiki.qt.io/Coding_Conventions
