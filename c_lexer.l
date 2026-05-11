%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_parser.tab.h"
#include "token_logger.h"

// For tracking line numbers
int line_num = 1;

// External token logger
extern TokenLog* global_token_log;

// Helper macro to log tokens
#define LOG_TOKEN(type, value) \
    do { if (global_token_log) add_token(global_token_log, type, value, line_num); } while(0)
%}

/* States */
%x COMMENT
%x LINE_COMMENT
%x PREPROCESSOR

/* Regular expressions for various token patterns */
DIGIT       [0-9]
LETTER      [a-zA-Z_]
ID          {LETTER}({LETTER}|{DIGIT})*
NUMBER      {DIGIT}+(\.{DIGIT}+)?([eE][+-]?{DIGIT}+)?
WHITESPACE  [ \t\r\f\v]+
STRING      \"([^\"\n]|\\\")*\"
CHAR        \'([^\'\n]|\\.)*\'

%%

"/*"                    { BEGIN(COMMENT); }
<COMMENT>"*/"           { BEGIN(INITIAL); }
<COMMENT>\n             { line_num++; }
<COMMENT>.              { /* ignore other characters in comment */ }

"//"                    { BEGIN(LINE_COMMENT); }
<LINE_COMMENT>\n        { line_num++; BEGIN(INITIAL); }
<LINE_COMMENT>.         { /* ignore other characters in line comment */ }

^"#"                    { BEGIN(PREPROCESSOR); printf("Preprocessor directive at line %d\n", line_num); }
<PREPROCESSOR>\n        { line_num++; BEGIN(INITIAL); }
<PREPROCESSOR>.         { /* ignore characters in preprocessor directive */ }

\n                      { line_num++; }
{WHITESPACE}            { /* ignore whitespace */ }

"int"       { LOG_TOKEN("KEYWORD", "int"); return INT; }
"long"      { LOG_TOKEN("KEYWORD", "long"); return LONG; }
"float"     { LOG_TOKEN("KEYWORD", "float"); return FLOAT; }
"char"      { LOG_TOKEN("KEYWORD", "char"); return CHAR; }
"void"      { LOG_TOKEN("KEYWORD", "void"); return VOID; }
"return"    { LOG_TOKEN("KEYWORD", "return"); return RETURN; }
"if"        { LOG_TOKEN("KEYWORD", "if"); return IF; }
"else"      { LOG_TOKEN("KEYWORD", "else"); return ELSE; }
"while"     { LOG_TOKEN("KEYWORD", "while"); return WHILE; }
"for"       { LOG_TOKEN("KEYWORD", "for"); return FOR; }
"break"     { LOG_TOKEN("KEYWORD", "break"); return BREAK; }
"continue"  { LOG_TOKEN("KEYWORD", "continue"); return CONTINUE; }
"auto"      { LOG_TOKEN("KEYWORD", "auto"); return AUTO; }

"+"         { LOG_TOKEN("OPERATOR", "+"); return '+'; }
"-"         { LOG_TOKEN("OPERATOR", "-"); return '-'; }
"*"         { LOG_TOKEN("OPERATOR", "*"); return '*'; }
"/"         { LOG_TOKEN("OPERATOR", "/"); return '/'; }
"%"         { LOG_TOKEN("OPERATOR", "%"); return '%'; }
"="         { LOG_TOKEN("OPERATOR", "="); return '='; }
"<"         { LOG_TOKEN("OPERATOR", "<"); return '<'; }
">"         { LOG_TOKEN("OPERATOR", ">"); return '>'; }
"!"         { LOG_TOKEN("OPERATOR", "!"); return '!'; }
"&"         { LOG_TOKEN("OPERATOR", "&"); return '&'; }
"|"         { LOG_TOKEN("OPERATOR", "|"); return '|'; }
"^"         { LOG_TOKEN("OPERATOR", "^"); return '^'; }
"~"         { LOG_TOKEN("OPERATOR", "~"); return '~'; }
"?"         { LOG_TOKEN("OPERATOR", "?"); return '?'; }
":"         { LOG_TOKEN("PUNCTUATION", ":"); return ':'; }
";"         { LOG_TOKEN("PUNCTUATION", ";"); return ';'; }
","         { LOG_TOKEN("PUNCTUATION", ","); return ','; }
"."         { LOG_TOKEN("PUNCTUATION", "."); return '.'; }
"("         { LOG_TOKEN("PUNCTUATION", "("); return '('; }
")"         { LOG_TOKEN("PUNCTUATION", ")"); return ')'; }
"["         { LOG_TOKEN("PUNCTUATION", "["); return '['; }
"]"         { LOG_TOKEN("PUNCTUATION", "]"); return ']'; }
"{"         { LOG_TOKEN("PUNCTUATION", "{"); return '{'; }
"}"         { LOG_TOKEN("PUNCTUATION", "}"); return '}'; }

"++"        { return INC_OP; }
"--"        { return DEC_OP; }
"=="        { return EQ_OP; }
"!="        { return NE_OP; }
"<="        { return LE_OP; }
">="        { return GE_OP; }
"&&"        { return AND_OP; }
"||"        { return OR_OP; }
"<<"        { return LEFT_OP; }
">>"        { return RIGHT_OP; }
"->"        { return PTR_OP; }
"+="        { return ADD_ASSIGN; }
"-="        { return SUB_ASSIGN; }
"*="        { return MUL_ASSIGN; }
"/="        { return DIV_ASSIGN; }
"%="        { return MOD_ASSIGN; }
"&="        { return AND_ASSIGN; }
"^="        { return XOR_ASSIGN; }
"|="        { return OR_ASSIGN; }
"<<="       { return LEFT_ASSIGN; }
">>="       { return RIGHT_ASSIGN; }

{ID}        { 
              LOG_TOKEN("IDENTIFIER", yytext);
              yylval.str_val = strdup(yytext);
              return IDENTIFIER; 
            }

{NUMBER}    { 
              LOG_TOKEN("NUMBER", yytext);
              yylval.int_val = (int)atof(yytext);
              return NUMBER; 
            }

{STRING}    { 
              yylval.str_val = strdup(yytext);
              return STRING_LITERAL; 
            }

{CHAR}      { 
              yylval.str_val = strdup(yytext);
              return NUMBER; 
            }

.           { printf("Unrecognized character: %s at line %d\n", yytext, line_num); }

%%

int yywrap() {
    return 1;
}