/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_C_PARSER_TAB_H_INCLUDED
# define YY_YY_C_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    CHAR = 260,                    /* CHAR  */
    VOID = 261,                    /* VOID  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    WHILE = 264,                   /* WHILE  */
    FOR = 265,                     /* FOR  */
    DO = 266,                      /* DO  */
    SWITCH = 267,                  /* SWITCH  */
    CASE = 268,                    /* CASE  */
    DEFAULT = 269,                 /* DEFAULT  */
    BREAK = 270,                   /* BREAK  */
    CONTINUE = 271,                /* CONTINUE  */
    RETURN = 272,                  /* RETURN  */
    IDENTIFIER = 273,              /* IDENTIFIER  */
    NUMBER = 274,                  /* NUMBER  */
    INC_OP = 275,                  /* INC_OP  */
    DEC_OP = 276,                  /* DEC_OP  */
    LE_OP = 277,                   /* LE_OP  */
    GE_OP = 278,                   /* GE_OP  */
    EQ_OP = 279,                   /* EQ_OP  */
    NE_OP = 280,                   /* NE_OP  */
    AND_OP = 281,                  /* AND_OP  */
    OR_OP = 282,                   /* OR_OP  */
    AUTO = 283,                    /* AUTO  */
    CONST = 284,                   /* CONST  */
    DOUBLE = 285,                  /* DOUBLE  */
    ENUM = 286,                    /* ENUM  */
    EXTERN = 287,                  /* EXTERN  */
    GOTO = 288,                    /* GOTO  */
    LONG = 289,                    /* LONG  */
    REGISTER = 290,                /* REGISTER  */
    SHORT = 291,                   /* SHORT  */
    SIGNED = 292,                  /* SIGNED  */
    SIZEOF = 293,                  /* SIZEOF  */
    STATIC = 294,                  /* STATIC  */
    STRUCT = 295,                  /* STRUCT  */
    TYPEDEF = 296,                 /* TYPEDEF  */
    UNION = 297,                   /* UNION  */
    UNSIGNED = 298,                /* UNSIGNED  */
    VOLATILE = 299,                /* VOLATILE  */
    STRING_LITERAL = 300,          /* STRING_LITERAL  */
    LEFT_OP = 301,                 /* LEFT_OP  */
    RIGHT_OP = 302,                /* RIGHT_OP  */
    MUL_ASSIGN = 303,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 304,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 305,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 306,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 307,              /* SUB_ASSIGN  */
    LEFT_ASSIGN = 308,             /* LEFT_ASSIGN  */
    RIGHT_ASSIGN = 309,            /* RIGHT_ASSIGN  */
    AND_ASSIGN = 310,              /* AND_ASSIGN  */
    XOR_ASSIGN = 311,              /* XOR_ASSIGN  */
    OR_ASSIGN = 312,               /* OR_ASSIGN  */
    PTR_OP = 313,                  /* PTR_OP  */
    UNARY_MINUS = 314,             /* UNARY_MINUS  */
    LOWER_THAN_ELSE = 315          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 64 "c_parser.y"

    int int_val;
    char* str_val;

#line 129 "c_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_C_PARSER_TAB_H_INCLUDED  */
