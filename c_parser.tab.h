
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AUTO = 258,
     BREAK = 259,
     CASE = 260,
     CHAR = 261,
     CONST = 262,
     CONTINUE = 263,
     DEFAULT = 264,
     DO = 265,
     DOUBLE = 266,
     ELSE = 267,
     ENUM = 268,
     EXTERN = 269,
     FLOAT = 270,
     FOR = 271,
     GOTO = 272,
     IF = 273,
     INT = 274,
     LONG = 275,
     REGISTER = 276,
     RETURN = 277,
     SHORT = 278,
     SIGNED = 279,
     SIZEOF = 280,
     STATIC = 281,
     STRUCT = 282,
     SWITCH = 283,
     TYPEDEF = 284,
     UNION = 285,
     UNSIGNED = 286,
     VOID = 287,
     VOLATILE = 288,
     WHILE = 289,
     IDENTIFIER = 290,
     CONSTANT = 291,
     STRING_LITERAL = 292,
     INC_OP = 293,
     DEC_OP = 294,
     LEFT_OP = 295,
     RIGHT_OP = 296,
     LE_OP = 297,
     GE_OP = 298,
     EQ_OP = 299,
     NE_OP = 300,
     AND_OP = 301,
     OR_OP = 302,
     MUL_ASSIGN = 303,
     DIV_ASSIGN = 304,
     MOD_ASSIGN = 305,
     ADD_ASSIGN = 306,
     SUB_ASSIGN = 307,
     LEFT_ASSIGN = 308,
     RIGHT_ASSIGN = 309,
     AND_ASSIGN = 310,
     XOR_ASSIGN = 311,
     OR_ASSIGN = 312,
     PTR_OP = 313,
     IFX = 314
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 17 "c_parser.y"

    int int_val;
    double num_val;
    char* str_val;



/* Line 1676 of yacc.c  */
#line 119 "c_parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


