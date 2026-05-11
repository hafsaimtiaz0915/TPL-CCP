# TPL-CCP Compiler Project Report

## 1. Project Information

- **Project Title:** TPL-CCP (Compiler Construction Project)
- **Course Context:** Compiler Design / Programming Languages
- **Repository:** `github.com/hafsaimtiaz0915/TPL-CCP`
- **Report Version:** Updated after latest code integration
- **Date:** 2026-05-11

## 2. Abstract

This report presents the design and implementation status of TPL-CCP, a compiler for a simplified C-like language built using Flex and Bison, with semantic analysis, three-address code (TAC) generation, and TAC execution support. The codebase is organized as a multi-phase compilation pipeline with modular components for lexical analysis, parsing, symbol table management, semantic checks, intermediate representation generation, token logging, and virtual execution.

The updated repository includes enhanced AST/TAC visualization and a dedicated semantic analysis module, and it also includes documentation and test assets to support demonstration and evaluation.

## 3. Problem Statement

The project goal is to implement a complete, educational compiler pipeline for a restricted C-like language that can:

1. Recognize source code tokens.
2. Parse statements according to grammar rules.
3. Perform semantic validation.
4. Generate intermediate code (TAC).
5. Present structured compiler output.
6. Execute generated TAC for supported operations.

The compiler is designed to demonstrate compiler construction principles in a single cohesive system.

## 4. Objectives

1. Build a working lexer using Flex.
2. Build a parser using Bison with precedence handling for ambiguous constructs.
3. Maintain symbol information across nested scopes.
4. Detect common semantic errors (e.g., undeclared and redeclared variables).
5. Generate TAC for expressions and control flow.
6. Execute TAC with a virtual execution context.
7. Provide clear stage-wise output suitable for academic evaluation.

## 5. Scope and Language Coverage

### 5.1 In-Scope Constructs

- Basic data types and declarations (core `int`-focused flow is active in tests).
- Arithmetic and logical expressions.
- Assignment statements.
- Control flow (`if/else`, `while`, and related branching patterns).
- Function-oriented grammar constructs.
- Token and TAC output artifact generation.

### 5.2 Error Categories Covered

- Syntax errors from parser stage.
- Semantic errors, including:
  - Undeclared variable usage.
  - Redeclaration in invalid context.
  - Invalid loop-control usage (e.g., `break` / `continue` misuse).

### 5.3 Out-of-Scope / Partial Areas

- Full production-level C standard compliance.
- Advanced optimizations.
- Full backend machine-code generation.
- Complete integration of every advanced semantic routine into main build flow.

## 6. System Architecture

The implementation follows a staged architecture:

1. **Lexical Analysis** (`c_lexer.l`, generated `lex.yy.c`)
2. **Syntax Analysis** (`c_parser.y`, generated parser files)
3. **Semantic Handling** (`symbol_table.*`, parser callbacks, `semantic_analysis.*` support module)
4. **IR Generation (TAC)** (`codegen.*`)
5. **Formatted Display / Reporting** (`main.c`, enhanced AST/TAC display support)
6. **Execution** (`tac_executor.*`)

## 7. Module-Wise Implementation Summary

### 7.1 Lexical Analysis

- Implemented through Flex definitions in `c_lexer.l`.
- Supports tokenization for keywords, identifiers, numbers, operators, and separators.
- Captured tokens are persisted through `token_logger.*`.

### 7.2 Syntax Analysis

- Implemented through Bison grammar in `c_parser.y`.
- Grammar includes expression and control-flow productions.
- Conflict handling includes precedence-based approach for dangling-`else` style ambiguity.

### 7.3 Symbol Table and Scope Management

- Implemented in `symbol_table.c`/`.h`.
- Supports symbol insertion, lookup, and scope enter/exit operations.
- Used by parser and semantic checks during compilation.

### 7.4 Semantic Analysis

- Core semantic checks are integrated in pipeline flow via parser/main interactions.
- Additional semantic analysis support functions are present in:
  - `semantic_analysis.h`
  - `semantic_analysis.c`
- Includes routines for type compatibility checks, assignment validation, function/return checks, and control-flow-related validation helpers.

### 7.5 Intermediate Representation (TAC)

- TAC generation is handled by `codegen.c`/`.h`.
- Covers assignment, arithmetic, comparison, and control-flow forms.
- TAC can be printed and saved for inspection.

### 7.6 Enhanced AST/TAC Display

- Added visualization support in:
  - `ast_enhanced.h`
  - `ast_enhanced.c`
- Provides structured, readable rendering of AST/TAC-oriented output for demonstration and debugging.

### 7.7 TAC Execution

- Implemented in `tac_executor.c`/`.h`.
- Executes TAC instructions in a virtual execution context.
- Reports variable states after execution for supported instruction types.

## 8. Build and Execution Status

### 8.1 Build Tooling in Repository

- Primary build script: `Makefile`
- Auxiliary scripts: `build.bat`, `build.ps1`

### 8.2 Current Integration Note (Important)

The latest source includes references to enhanced modules (`ast_enhanced.*`, `semantic_analysis.*`) from `main.c`. The current `Makefile` object list does not include all newly required compilation units. As a result, default Linux build currently fails at link stage with unresolved symbol(s) unless build inputs are updated.

This report reflects the updated code state and its module additions.

## 9. Testing Assets and Validation Approach

### 9.1 Available Test Inputs

The repository includes multiple test programs, such as:

- Valid-flow oriented: `test_valid_simple.c`, `test_valid_arithmetic.c`, `test_valid_scope.c`, `test_valid_ifelse.c`, `test_valid_while.c`, `test_valid_function.c`
- Error-oriented: `test_syntax_nosemi.c`, `test_semantic_undeclared.c`, `test_semantic_redecl.c`, `test_semantic_breakout.c`
- Additional branch/control and scenario files are also present for experimentation.

### 9.2 Validation Strategy

1. Build compiler components.
2. Run valid test files and inspect stage outputs and generated artifacts.
3. Run negative tests and verify clear syntax/semantic error reporting.
4. Validate TAC generation and execution behavior for arithmetic/control cases.

## 10. Key Updates Reflected in This Report

Compared with earlier project documentation, the updated codebase now explicitly includes:

1. Enhanced AST/TAC visualization module.
2. Dedicated semantic analysis helper module.
3. Grammar updates to improve ambiguity handling (including dangling-`else` treatment).
4. Expanded supporting documentation and comparison notes in repository markdown files.

## 11. Limitations and Risks

1. Build configuration currently needs synchronization with newly referenced modules.
2. Some advanced language tokens/rules are defined for breadth, while practical execution coverage remains focused on core educational constructs.
3. Full compiler hardening (strict warning cleanup, optimization pipeline, backend portability) remains future work.

## 12. Recommendations

1. Update `Makefile` source/object lists to include all active modules referenced by `main.c`.
2. Define a canonical automated regression command for all provided tests.
3. Consolidate semantic checks to avoid overlap between parser-level and module-level logic.
4. Add versioned release notes for each compiler milestone.

## 13. Conclusion

TPL-CCP demonstrates a complete educational compiler pipeline with modular architecture and clear progression from source input to intermediate code execution. The latest repository state shows substantial evolution through enhanced analysis and visualization components. With minor build-configuration alignment and continued regression validation, the project is in strong condition for formal academic submission and further incremental extension.

## 14. References (Repository Artifacts)

- `README.md`
- `Makefile`
- `c_lexer.l`
- `c_parser.y`
- `main.c`
- `symbol_table.c`, `symbol_table.h`
- `codegen.c`, `codegen.h`
- `tac_executor.c`, `tac_executor.h`
- `token_logger.c`, `token_logger.h`
- `semantic_analysis.c`, `semantic_analysis.h`
- `ast_enhanced.c`, `ast_enhanced.h`
- Test files: `test_*.c`
