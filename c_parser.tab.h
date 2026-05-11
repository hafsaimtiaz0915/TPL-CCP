
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
     INT = 258,
     FLOAT = 259,
     CHAR = 260,
     VOID = 261,
     IF = 262,
     ELSE = 263,
     WHILE = 264,
     FOR = 265,
     DO = 266,
     SWITCH = 267,
     CASE = 268,
     DEFAULT = 269,
     BREAK = 270,
     CONTINUE = 271,
     RETURN = 272,
     IDENTIFIER = 273,
     NUMBER = 274,
     INC_OP = 275,
     DEC_OP = 276,
     LE_OP = 277,
     GE_OP = 278,
     EQ_OP = 279,
     NE_OP = 280,
     AND_OP = 281,
     OR_OP = 282,
     AUTO = 283,
     CONST = 284,
     DOUBLE = 285,
     ENUM = 286,
     EXTERN = 287,
     GOTO = 288,
     LONG = 289,
     REGISTER = 290,
     SHORT = 291,
     SIGNED = 292,
     SIZEOF = 293,
     STATIC = 294,
     STRUCT = 295,
     TYPEDEF = 296,
     UNION = 297,
     UNSIGNED = 298,
     VOLATILE = 299,
     STRING_LITERAL = 300,
     LEFT_OP = 301,
     RIGHT_OP = 302,
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
     UNARY_MINUS = 314,
     LOWER_THAN_ELSE = 315
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 64 "c_parser.y"

    int int_val;
    char* str_val;



/* Line 1676 of yacc.c  */
#line 119 "c_parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


