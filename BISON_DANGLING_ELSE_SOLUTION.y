/* ================================================================
   DANGLING-ELSE GRAMMAR FIX FOR GNU BISON
   ================================================================
   
   This file shows the EXACT grammar rules needed to fix the
   dangling-else shift/reduce conflict using the standard 
   precedence method with proper TAC generation via mid-rule actions.
   
   ================================================================ */

%{
/* Place your C declarations here (lex, symbol table, TAC codegen, etc.) */
%}

%union {
    char* str_val;
}

%token IF ELSE
%token IDENTIFIER NUMBER
%token ';' '(' ')' '{' '}'

/* Operator precedence (for expression handling) */
%left '+' '-'
%left '*' '/' '%'
%right UNARY_MINUS

/* *** DANGLING-ELSE FIX *** */
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%type <str_val> expression

%start program

%%

program
    : statement_list
    ;

statement_list
    : /* empty */
    | statement_list statement
    ;

statement
    : expression ';'
    | '{' statement_list '}'
    | if_statement
    ;

/* ================================================================
   IF-STATEMENT GRAMMAR WITH DANGLING-ELSE FIX
   
   Key points:
   1. Two productions: if-only and if-else
   2. %prec LOWER_THAN_ELSE on if-only makes it reduce-action
   3. When ELSE seen: parser shifts ELSE (not reduces if-only)
   4. Result: ELSE binds to nearest unmatched if ✓
   
   ================================================================ */

if_statement
    /* Production 1: Simple IF (no else) */
    : IF '(' expression ')' 
    {
        /* Mid-rule action: after condition, before body */
        /* Emit: if_false_jump to else/end label */
        emit_if_false($3);
        push_label_for_end_of_if();
    }
    statement %prec LOWER_THAN_ELSE    /* <<< CRITICAL: %prec directive */
    {
        /* Mid-rule action: after body, before else (if any) */
        /* Emit: label for end_of_if */
        emit_label_end_of_if();
        pop_label();
    }
    
    /* Production 2: IF-ELSE */
    | IF '(' expression ')' 
    {
        /* Mid-rule action: after condition */
        /* Emit: if_false_jump to else_label */
        emit_if_false($3);
        push_labels_for_ifelse();
    }
    statement ELSE
    {
        /* Mid-rule action: between then-body and else-body */
        /* Emit: unconditional_goto end_label */
        /* Emit: label for else_start */
        emit_goto_end();
        emit_label_else_start();
    }
    statement
    {
        /* Mid-rule action: after else-body */
        /* Emit: label for end_of_ifelse */
        emit_label_end_of_ifelse();
        pop_labels();
    }
    ;

expression
    : IDENTIFIER
    | NUMBER
    | expression '+' expression
    | expression '-' expression
    | expression '*' expression
    | expression '/' expression
    | '(' expression ')'
    ;

%%

/* ================================================================
   HOW THIS FIXES THE DANGLING-ELSE CONFLICT
   ================================================================
   
   Without %prec:
   ✗ Shift/Reduce conflict: "if (c1) if (c2) s; else ..."
   ✗ Parser doesn't know: Reduce inner-if or shift ELSE?
   ✗ Wrong: Some parses bind else to outer if
   
   With %prec LOWER_THAN_ELSE:
   ✓ Bison knows: ELSE token has higher precedence
   ✓ When seeing ELSE: SHIFT (don't reduce if-only)
   ✓ ELSE binds to nearest unmatched if (correct!)
   ✓ Result: Zero dangling-else conflicts
   
   ================================================================ */
