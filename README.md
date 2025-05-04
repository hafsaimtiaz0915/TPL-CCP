# TPL-CCP: C Compiler Project

A lexical and syntax analyzer for the C programming language, developed as part of the Theory of Programming Languages course (CT-367).

## Project Overview

This project implements a front-end compiler for the C programming language, focusing on the lexical analysis and syntax analysis phases. It uses Flex for lexical analysis and Bison for syntax analysis to tokenize and parse C code according to the C language grammar.

## Features

### Lexical Analysis
- Tokenization of keywords, identifiers, constants, operators, and punctuators
- Recognition of comments (both single-line and multi-line)
- Handling of preprocessor directives
- Line number tracking for error reporting
- String and character literal processing

### Syntax Analysis
- Parsing of declarations and definitions
- Handling of expressions and statements
- Recognition of control structures (if-else, loops, switch)
- Support for function definitions and calls
- Parsing of complex data types (structs, enums)
- Error reporting with line numbers

## Building and Running

To build the project, use the following commands:

```bash
bison -d c_parser.y
flex c_lexer.l
gcc -Wall -g -o c_compiler.exe lex.yy.c c_parser.tab.c
```

To run the compiler on a C file:

```bash
c_compiler.exe simple_test.c
```

## Limitations

1. **Variable Declaration Restrictions**: All variable declarations must be at the start of a code block.

2. **Platform-Specific Issues**: When compiling on Windows systems, there may be warnings related to library handling since Windows handles these libraries differently than Unix-based systems. The warnings about unused functions can be ignored - they're normal when using Flex.

3. **Multiple Variable Declarations**: The current implementation has difficulty parsing multiple variable declarations in a single statement (e.g., `int a = 10, b = 5;`).

4. **Advanced C Features**: The analyzer doesn't support some C99/C11 features like variable-length arrays, inline functions, compound literals, designated initializers, and specialized types.

5. **Limited Analysis**: This is a front-end only implementation with no semantic analysis, type checking, code generation, or optimization.

## Team Members

- Hafsa Imtiaz (CT-22060)
- Zainab Furqan Ahmed (CT-22067)
- Sheeza Aslam (CT-22064)

## Course Information

- **Course:** Theory Of Programming Language (CT-367)
- **Department:** Computer Science and Information Technology
- **Batch:** 2022, Section B
- **Semester:** Spring 2024

## Additional Resources

Full project report: [Google Docs Link](https://docs.google.com/document/d/1hoNyk6UeFu9EHf0seE_ig18rnCIFp-8fIpcmVt16LPU/edit?usp=sharing)

