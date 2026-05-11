# DEPARTMENT OF COMPUTER SCIENCE & INFORMATION TECHNOLOGY  
# BACHELORS OF SCIENCE IN COMPUTER SCIENCE  
## Compiler Design (CT-465) — CCP Formal Project Report

---

## 1. Course and Project Context

- **Course Title and Code:** Compiler Design (CT-465)
- **Course Learning Outcome (CLO 1):** Design and implement a compiler for a simplified programming language by applying formal language theory and compiler construction techniques.
- **Repository:** https://github.com/hafsaimtiaz0915/TPL-CCP
- **Project Type:** Compiler Construction Project (CCP)
- **Submission Components:** Report, code, presentation slides

---

## 2. CLO and Complex Problem Attribute (CPA) Mapping

### 2.1 CLO 1 Alignment
This project demonstrates a full compiler pipeline for a simplified C-like language, including lexical analysis, syntax analysis, semantic checks, intermediate code generation, and execution support.

### 2.2 CPA Mapping (NCEAC 2021 / Seoul Accord)

#### CPA-2: Depth of Analysis Required
- The project has no single obvious implementation path.
- Grammar design, ambiguity handling (e.g., dangling-else), and intermediate-code design require conceptual and iterative analysis.
- Scope handling and semantic rule selection require abstract modeling choices.

#### CPA-3: Depth of Knowledge Required
- Uses in-depth compiler concepts: tokenization, parsing, precedence rules, symbol tables, TAC generation, and virtual execution.
- Uses formal tools (Flex/Bison) with language-theory-driven construction.

#### CPA-9: Requirement Identification
- Practical requirements are interpreted from an open-ended case (ABC Tech embedded-language scenario).
- Functional subset and implementation constraints are identified through explicit assumptions.

---

## 3. Problem Statement

Design and implement a compiler for a simplified programming language that translates high-level source code into executable/intermediate form, with clear syntax and semantic error reporting, and suitability for resource-constrained target scenarios.

---

## 4. Problem Description (ABC Tech Case)

ABC Tech requires a lightweight language and compiler for embedded-oriented use, with support for:
- Integer-centric programming constructs
- Conditional execution (`if-else`)
- Loops (`while`, and related control behavior)
- Error detection and user-friendly diagnostics
- Intermediate representation generation for a hypothetical VM

The implemented project addresses these needs through a modular compiler architecture and extensible design.

---

## 5. Project Objectives

1. Implement lexical analysis for a simplified C-like language.
2. Implement syntax analysis using CFG-based parser construction.
3. Implement semantic checks with scoped symbol management.
4. Generate intermediate code (Three-Address Code / TAC).
5. Provide a basic execution model for generated TAC.
6. Produce readable compiler-stage outputs for academic demonstration.

---

## 6. Formal Design Deliverable

## 6.1 Context-Free Grammar (CFG)

The implemented grammar in `c_parser.y` supports declarations, statements, expressions, and control-flow constructs. A representative simplified CFG subset is:

```bnf
program            -> /* empty */ | program declaration

declaration        -> var_declaration | function_declaration

var_declaration    -> type_specifier IDENTIFIER ';'
                    | type_specifier IDENTIFIER '=' expression ';'
                    | type_specifier IDENTIFIER '[' NUMBER ']' ';'

type_specifier     -> 'int' | 'float' | 'char' | 'void'

function_declaration
                   -> type_specifier IDENTIFIER '(' ')' '{' statement_list '}'
                    | type_specifier IDENTIFIER '(' parameter_list ')' '{' statement_list '}'

statement_list     -> /* empty */ | statement_list statement

statement          -> expression ';'
                    | var_declaration
                    | '{' statement_list '}'
                    | if_statement
                    | while_statement
                    | for_statement
                    | 'break' ';'
                    | 'continue' ';'
                    | 'return' ';'
                    | 'return' expression ';'

if_statement       -> 'if' '(' expression ')' statement
                    | 'if' '(' expression ')' statement 'else' statement

expression         -> IDENTIFIER
                    | NUMBER
                    | IDENTIFIER '=' expression
                    | expression '+' expression
                    | expression '-' expression
                    | expression '*' expression
                    | expression '/' expression
                    | expression '%' expression
                    | '(' expression ')'
                    | IDENTIFIER '(' ')'
                    | IDENTIFIER '(' expression ')'
```

### Ambiguity Handling
The grammar includes precedence-based dangling-else handling (`%nonassoc LOWER_THAN_ELSE` and `%nonassoc ELSE`) so `else` binds to the nearest unmatched `if`.

---

## 6.2 FSM / Regular Expressions for Lexical Analysis

Lexical analysis is defined in `c_lexer.l` using start states and regex rules.

### Lexer States
- `INITIAL`
- `COMMENT`
- `LINE_COMMENT`
- `PREPROCESSOR`

### Core Regex Definitions
```lex
DIGIT       [0-9]
LETTER      [a-zA-Z_]
ID          {LETTER}({LETTER}|{DIGIT})*
NUMBER      {DIGIT}+(\.{DIGIT}+)?([eE][+-]?{DIGIT}+)?
WHITESPACE  [ \t\r\f\v]+
STRING      \"([^\"\n]|\\\")*\"
CHAR        \'([^\'\n]|\\.)*\'
```

### FSM-Oriented Behavior (Textual)
1. **Identifier/Keyword FSM:** Start -> LETTER -> (LETTER|DIGIT)* -> accept token (keyword if reserved else identifier).
2. **Number FSM:** Start -> DIGIT+ -> optional decimal/exponent -> accept numeric token.
3. **Comment FSM:** `/* ... */` block comments and `// ...` line comments consumed in dedicated states.
4. **Preprocessor FSM:** Lines beginning with `#` handled in `PREPROCESSOR` state and skipped from token stream logic.

---

## 6.3 Symbol Table Structure and Semantic Checks

Symbol table implementation is defined in `symbol_table.h` / `symbol_table.c`.

### Symbol Entry Structure (Implemented)
Each symbol stores:
- `name`
- `type`
- `scope_level`
- `line_declared`
- `initialized`
- `is_function`
- `is_array`
- `array_size`
- `is_parameter`
- function parameter metadata (`param_types`, `param_count`)

### Symbol Table Operations
- `insert_symbol(...)`
- `lookup_symbol(...)`
- `lookup_symbol_in_scope(...)`
- `enter_scope(...)`
- `exit_scope(...)`
- `print_symbol_table(...)`

### Semantic Checks (Current Project Coverage)
- Redeclaration detection
- Undeclared variable usage detection
- Context validation for `break`, `continue`, and `return`
- Scope-aware symbol resolution
- Additional semantic helper module exists in `semantic_analysis.c/.h` for extended checks

---

## 7. Implementation Deliverable

## 7.1 Compiler Architecture (Current Repository)

The implementation follows a six-stage practical pipeline:

1. **Lexical Analysis** (`c_lexer.l` -> `lex.yy.c`)
2. **Syntax Analysis** (`c_parser.y` -> `c_parser.tab.c/.h`)
3. **Semantic Analysis** (parser checks + `symbol_table.*`)
4. **IR Generation** (`codegen.*`, TAC output)
5. **Formatted Stage Reporting** (`main.c`, plus enhanced display hooks)
6. **TAC Execution** (`tac_executor.*`)

## 7.2 Core Source Modules

- `main.c` — compiler driver and stage output
- `c_lexer.l` — lexer rules
- `c_parser.y` — parser grammar and parser actions
- `symbol_table.c/.h` — symbol/scope management
- `codegen.c/.h` — TAC generation
- `tac_executor.c/.h` — TAC execution engine
- `token_logger.c/.h` — token capture and export
- `ast_enhanced.c/.h` — enhanced AST/TAC display support
- `semantic_analysis.c/.h` — extended semantic analysis utilities

## 7.3 Build and Run

### Makefile Build Flow
```bash
make clean
make
make test
```

### Current Known Build Status
The current `Makefile` does not include all modules referenced by `main.c` (`ast_enhanced` and `semantic_analysis` linkage path), which causes linker failure (`undefined reference to printTACEnhanced`) in Linux build flow. This is a known integration issue pending remediation.

---

## 8. Assumptions and Trade-offs Deliverable

## 8.1 Project Assumptions (Implemented Scope)

1. The compiler targets a simplified C-like subset for educational use.
2. Core analysis and demonstration are integer-centric in test scenarios.
3. Intermediate code (TAC) is used as executable-level output for VM-style execution.
4. Error handling prioritizes syntax and key semantic issues over full ISO C compliance.
5. Architecture favors understandability and modularity over advanced optimization.

## 8.2 Trade-offs

- **Single educational pipeline vs. aggressive optimization:** simpler implementation, easier explanation.
- **Broad token support vs. full standards compliance:** extensible but not complete C compiler behavior.
- **Readable output and diagnostics vs. minimal runtime overhead:** output is verbose for pedagogy.

---

## 9. Testing and Validation

## 9.1 Test Assets in Repository

### Valid-focused tests
- `test_valid_simple.c`
- `test_valid_arithmetic.c`
- `test_valid_scope.c`
- `test_valid_ifelse.c`
- `test_valid_while.c`
- `test_valid_function.c`

### Error-focused tests
- `test_syntax_nosemi.c`
- `test_semantic_undeclared.c`
- `test_semantic_redecl.c`
- `test_semantic_breakout.c`

### Additional scenarios
Multiple `test_*.c` files for branch and control-flow experimentation are available.

## 9.2 Validation Approach

1. Build compiler artifacts.
2. Execute compiler on valid test inputs.
3. Verify stage outputs and generated `.tac` / `.tokens` files.
4. Execute error tests and verify diagnostics include appropriate semantic/syntax context.

---

## 10. Results Summary

- Implemented compiler pipeline across lexical, syntax, semantic, IR, and execution layers.
- Implemented scoped symbol management and parser-integrated semantic checks.
- Generated TAC for arithmetic and control-flow patterns.
- Added enhanced AST/TAC reporting and an extended semantic-analysis module.
- Maintained broad repository test assets for demonstration.

---

## 11. Presentation Deliverable Guidance (10–15 Minutes)

## 11.1 Required Slide Outline

1. **Title Slide** — Course, project title, group members, date.
2. **Problem Statement** — ABC Tech case and requirement identification (CPA-9).
3. **Research and Principles** — Compiler phases, Flex/Bison rationale (CPA-3).
4. **Formal Design** — CFG, FSM/regex, symbol table and semantic checks (CPA-2).
5. **Implementation** — architecture, modules, key workflow.
6. **Assumptions and Trade-offs** — scope boundaries and design decisions.
7. **Demo** — sample input, compiler output, error case.
8. **Conclusion and Future Work** — summary and next enhancements.
9. **Q&A**.

## 11.2 Demo Recommendations

- Show one valid file and one semantic error file.
- Highlight token log, symbol table output, TAC output, and error message clarity.
- Keep demo deterministic and short (2–4 minutes inside total slot).

---

## 12. Submission Checklist

- [x] Formal report includes CLO/CPA mapping.
- [x] Formal design includes CFG, lexical model (FSM/regex), symbol table + semantic checks.
- [x] Implementation section maps repository modules.
- [x] Assumptions and trade-offs are documented.
- [x] Presentation structure for 10–15 minute session is provided.
- [x] Testing assets and validation approach are documented.

---

## 13. Future Work

1. Resolve Makefile integration issue for full Linux build success.
2. Integrate extended semantic analysis module fully into default compile path.
3. Reduce parser conflicts and improve grammar robustness.
4. Add optimization stage (constant folding / dead-code elimination).
5. Improve CI/regression automation for all test programs.

---

## 14. References (Repository Artifacts)

- `/home/runner/work/TPL-CCP/TPL-CCP/c_parser.y`
- `/home/runner/work/TPL-CCP/TPL-CCP/c_lexer.l`
- `/home/runner/work/TPL-CCP/TPL-CCP/symbol_table.h`
- `/home/runner/work/TPL-CCP/TPL-CCP/symbol_table.c`
- `/home/runner/work/TPL-CCP/TPL-CCP/codegen.h`
- `/home/runner/work/TPL-CCP/TPL-CCP/codegen.c`
- `/home/runner/work/TPL-CCP/TPL-CCP/tac_executor.h`
- `/home/runner/work/TPL-CCP/TPL-CCP/tac_executor.c`
- `/home/runner/work/TPL-CCP/TPL-CCP/main.c`
- `/home/runner/work/TPL-CCP/TPL-CCP/Makefile`
- `/home/runner/work/TPL-CCP/TPL-CCP/README.md`

