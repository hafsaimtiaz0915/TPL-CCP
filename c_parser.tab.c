/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "c_parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "codegen.h"
#include "token_logger.h"

extern int yylex();
extern int line_num;
extern char* yytext;
extern FILE* yyin;

extern SymbolTable* sym_table;
extern CodeGenerator* code_gen;
extern TokenLog* global_token_log;
extern int semantic_error_count;

int in_loop = 0;
int in_function = 0;
int temp_counter = 0;
int label_counter = 0;
int loop_start_stack[100];  /* Stack for loop start labels */
int loop_end_stack[100];    /* Stack for loop end labels */
int loop_label_top = -1;    /* Stack pointer */

void yyerror(const char *s);

char* new_temp(void) {
    static char temp_name[20];
    sprintf(temp_name, "t%d", temp_counter++);
    return strdup(temp_name);
}

int new_label(void) {
    return code_gen->label_counter++;
}

void push_loop_labels(int start, int end) {
    if (loop_label_top < 99) {
        loop_label_top++;
        loop_start_stack[loop_label_top] = start;
        loop_end_stack[loop_label_top] = end;
    }
}

void pop_loop_labels(int *start, int *end) {
    if (loop_label_top >= 0) {
        *start = loop_start_stack[loop_label_top];
        *end = loop_end_stack[loop_label_top];
        loop_label_top--;
    }
}

int peek_loop_end(void) {
    if (loop_label_top >= 0) {
        return loop_end_stack[loop_label_top];
    }
    return -1;
}


#line 134 "c_parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "c_parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_DO = 11,                        /* DO  */
  YYSYMBOL_SWITCH = 12,                    /* SWITCH  */
  YYSYMBOL_CASE = 13,                      /* CASE  */
  YYSYMBOL_DEFAULT = 14,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 15,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 16,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_IDENTIFIER = 18,                /* IDENTIFIER  */
  YYSYMBOL_NUMBER = 19,                    /* NUMBER  */
  YYSYMBOL_20_ = 20,                       /* '+'  */
  YYSYMBOL_21_ = 21,                       /* '-'  */
  YYSYMBOL_22_ = 22,                       /* '*'  */
  YYSYMBOL_23_ = 23,                       /* '/'  */
  YYSYMBOL_24_ = 24,                       /* '%'  */
  YYSYMBOL_25_ = 25,                       /* '='  */
  YYSYMBOL_26_ = 26,                       /* '<'  */
  YYSYMBOL_27_ = 27,                       /* '>'  */
  YYSYMBOL_28_ = 28,                       /* '!'  */
  YYSYMBOL_29_ = 29,                       /* '&'  */
  YYSYMBOL_30_ = 30,                       /* '|'  */
  YYSYMBOL_31_ = 31,                       /* '^'  */
  YYSYMBOL_32_ = 32,                       /* '~'  */
  YYSYMBOL_INC_OP = 33,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 34,                    /* DEC_OP  */
  YYSYMBOL_LE_OP = 35,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 36,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 37,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 38,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 39,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 40,                     /* OR_OP  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* '{'  */
  YYSYMBOL_44_ = 44,                       /* '}'  */
  YYSYMBOL_45_ = 45,                       /* '('  */
  YYSYMBOL_46_ = 46,                       /* ')'  */
  YYSYMBOL_47_ = 47,                       /* '['  */
  YYSYMBOL_48_ = 48,                       /* ']'  */
  YYSYMBOL_AUTO = 49,                      /* AUTO  */
  YYSYMBOL_CONST = 50,                     /* CONST  */
  YYSYMBOL_DOUBLE = 51,                    /* DOUBLE  */
  YYSYMBOL_ENUM = 52,                      /* ENUM  */
  YYSYMBOL_EXTERN = 53,                    /* EXTERN  */
  YYSYMBOL_GOTO = 54,                      /* GOTO  */
  YYSYMBOL_LONG = 55,                      /* LONG  */
  YYSYMBOL_REGISTER = 56,                  /* REGISTER  */
  YYSYMBOL_SHORT = 57,                     /* SHORT  */
  YYSYMBOL_SIGNED = 58,                    /* SIGNED  */
  YYSYMBOL_SIZEOF = 59,                    /* SIZEOF  */
  YYSYMBOL_STATIC = 60,                    /* STATIC  */
  YYSYMBOL_STRUCT = 61,                    /* STRUCT  */
  YYSYMBOL_TYPEDEF = 62,                   /* TYPEDEF  */
  YYSYMBOL_UNION = 63,                     /* UNION  */
  YYSYMBOL_UNSIGNED = 64,                  /* UNSIGNED  */
  YYSYMBOL_VOLATILE = 65,                  /* VOLATILE  */
  YYSYMBOL_STRING_LITERAL = 66,            /* STRING_LITERAL  */
  YYSYMBOL_LEFT_OP = 67,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 68,                  /* RIGHT_OP  */
  YYSYMBOL_MUL_ASSIGN = 69,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 70,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 71,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 72,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 73,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 74,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 75,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 76,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 77,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 78,                 /* OR_ASSIGN  */
  YYSYMBOL_PTR_OP = 79,                    /* PTR_OP  */
  YYSYMBOL_UNARY_MINUS = 80,               /* UNARY_MINUS  */
  YYSYMBOL_LOWER_THAN_ELSE = 81,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 82,                  /* $accept  */
  YYSYMBOL_program = 83,                   /* program  */
  YYSYMBOL_declaration = 84,               /* declaration  */
  YYSYMBOL_var_declaration = 85,           /* var_declaration  */
  YYSYMBOL_type_specifier = 86,            /* type_specifier  */
  YYSYMBOL_parameter_list = 87,            /* parameter_list  */
  YYSYMBOL_function_declaration = 88,      /* function_declaration  */
  YYSYMBOL_89_1 = 89,                      /* $@1  */
  YYSYMBOL_90_2 = 90,                      /* $@2  */
  YYSYMBOL_statement_list = 91,            /* statement_list  */
  YYSYMBOL_statement = 92,                 /* statement  */
  YYSYMBOL_93_3 = 93,                      /* $@3  */
  YYSYMBOL_if_statement = 94,              /* if_statement  */
  YYSYMBOL_95_4 = 95,                      /* $@4  */
  YYSYMBOL_96_5 = 96,                      /* $@5  */
  YYSYMBOL_97_6 = 97,                      /* $@6  */
  YYSYMBOL_while_statement = 98,           /* while_statement  */
  YYSYMBOL_99_7 = 99,                      /* $@7  */
  YYSYMBOL_100_8 = 100,                    /* $@8  */
  YYSYMBOL_for_statement = 101,            /* for_statement  */
  YYSYMBOL_102_9 = 102,                    /* $@9  */
  YYSYMBOL_103_10 = 103,                   /* $@10  */
  YYSYMBOL_104_11 = 104,                   /* $@11  */
  YYSYMBOL_expression = 105                /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   410

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,     2,     2,    24,    29,     2,
      45,    46,    22,    20,    42,    21,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
      26,    25,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,    30,    44,    32,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    33,    34,    35,    36,    37,
      38,    39,    40,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   102,   102,   103,   107,   108,   112,   120,   129,   140,
     141,   142,   143,   147,   153,   162,   162,   176,   176,   193,
     194,   198,   201,   202,   202,   208,   209,   210,   211,   217,
     223,   229,   261,   260,   276,   285,   275,   304,   312,   303,
     332,   340,   349,   331,   363,   371,   375,   381,   387,   393,
     399,   405,   411,   417,   423,   429,   435,   441,   447,   453,
     458,   463,   466
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "CHAR",
  "VOID", "IF", "ELSE", "WHILE", "FOR", "DO", "SWITCH", "CASE", "DEFAULT",
  "BREAK", "CONTINUE", "RETURN", "IDENTIFIER", "NUMBER", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'='", "'<'", "'>'", "'!'", "'&'", "'|'", "'^'",
  "'~'", "INC_OP", "DEC_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "';'", "','", "'{'", "'}'", "'('", "')'", "'['", "']'", "AUTO",
  "CONST", "DOUBLE", "ENUM", "EXTERN", "GOTO", "LONG", "REGISTER", "SHORT",
  "SIGNED", "SIZEOF", "STATIC", "STRUCT", "TYPEDEF", "UNION", "UNSIGNED",
  "VOLATILE", "STRING_LITERAL", "LEFT_OP", "RIGHT_OP", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN",
  "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "PTR_OP",
  "UNARY_MINUS", "LOWER_THAN_ELSE", "$accept", "program", "declaration",
  "var_declaration", "type_specifier", "parameter_list",
  "function_declaration", "$@1", "$@2", "statement_list", "statement",
  "$@3", "if_statement", "$@4", "$@5", "$@6", "while_statement", "$@7",
  "$@8", "for_statement", "$@9", "$@10", "$@11", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-58)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -58,   172,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -15,
     -58,    -9,   116,   -58,     6,    12,   -21,   -58,   116,   116,
     116,   231,    -3,    16,   -41,   -13,   116,   370,   341,   147,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   -58,   -58,   -58,   113,    -2,     9,   341,
     -58,   347,   347,   370,   370,   370,   341,   341,   341,   341,
     341,   341,   341,   341,   -58,    33,   -58,   -58,    39,   -58,
     -58,     8,    14,    17,    20,    22,    52,   -58,   -58,   -58,
      47,   -58,   -58,   -58,   -58,   253,    85,   116,   -58,   116,
     -58,   -58,   -58,   275,   -58,    -8,   -58,   -58,   168,   116,
     297,   -58,   105,   -58,   189,   -58,   -58,   136,   136,   -58,
     116,   -58,    58,   136,   319,   -58,   -58,   -58,   136,   116,
     -58,   210,   -58,   136,   -58
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     9,    10,    11,    12,     3,     4,     0,
       5,     0,     0,     6,     0,     0,    44,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    59,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,    15,    13,     0,     0,     0,    62,
      61,    46,    47,    48,    49,    50,    53,    54,    55,    56,
      51,    52,    57,    58,    19,     0,    17,     8,     0,    14,
      19,     0,     0,     0,     0,     0,     0,    23,    16,    22,
       0,    20,    25,    26,    27,     0,     0,     0,    37,     0,
      28,    29,    30,     0,    19,     0,    21,    18,     0,     0,
       0,    31,     0,    32,     0,    40,    24,     0,     0,    38,
       0,    33,     0,     0,     0,    35,    39,    41,     0,     0,
      36,     0,    42,     0,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -58,   -58,   -58,    67,     1,   -58,   -58,   -58,   -58,   -57,
     281,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     7,    79,    80,    24,    10,    64,    70,    68,
      81,    94,    82,   107,   108,   118,    83,    99,   113,    84,
     110,   119,   123,    85
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      21,    46,     9,    11,    26,    47,    27,    28,    29,     3,
       4,     5,     6,    86,    49,    23,    12,    12,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    25,    13,    13,    45,    48,    14,   102,    15,    15,
      44,    66,     3,     4,     5,     6,    71,    65,    72,    73,
      67,    69,    22,    87,    74,    75,    76,    16,    17,    88,
      18,    90,    89,    91,    93,    95,   115,    19,     8,     0,
      16,    17,     0,    18,     0,    98,     0,   100,     0,     0,
      19,     0,    77,    78,    20,     0,     0,   104,     3,     4,
       5,     6,    71,    92,    72,    73,     0,    20,   114,     0,
      74,    75,    76,    16,    17,     0,    18,   121,     3,     4,
       5,     6,    71,    19,    72,    73,     3,     4,     5,     6,
      74,    75,    76,    16,    17,     0,    18,     0,    77,    97,
      20,     0,     0,    19,    16,    17,     0,    18,     0,     3,
       4,     5,     6,    71,    19,    72,    73,     0,    77,   106,
      20,    74,    75,    76,    16,    17,     0,    18,     0,     0,
       0,    20,     0,     0,    19,     0,     0,    30,    31,    32,
      33,    34,     2,    35,    36,     3,     4,     5,     6,    77,
       0,    20,    37,    38,    39,    40,    41,    42,    30,    31,
      32,    33,    34,    50,    35,    36,     0,     0,     0,     0,
       0,     0,     0,    37,    38,    39,    40,    41,    42,    30,
      31,    32,    33,    34,   103,    35,    36,     0,     0,     0,
       0,     0,     0,     0,    37,    38,    39,    40,    41,    42,
      30,    31,    32,    33,    34,   109,    35,    36,     0,     0,
       0,     0,     0,     0,     0,    37,    38,    39,    40,    41,
      42,    30,    31,    32,    33,    34,   122,    35,    36,     0,
       0,     0,     0,     0,     0,     0,    37,    38,    39,    40,
      41,    42,    43,    30,    31,    32,    33,    34,     0,    35,
      36,     0,     0,     0,     0,     0,     0,     0,    37,    38,
      39,    40,    41,    42,    96,    30,    31,    32,    33,    34,
       0,    35,    36,     0,     0,     0,     0,     0,     0,     0,
      37,    38,    39,    40,    41,    42,   101,    30,    31,    32,
      33,    34,     0,    35,    36,     0,     0,     0,     0,     0,
       0,     0,    37,    38,    39,    40,    41,    42,   105,    30,
      31,    32,    33,    34,     0,    35,    36,     0,     0,     0,
       0,     0,     0,     0,    37,    38,    39,    40,    41,    42,
     117,    30,    31,    32,    33,    34,     0,    35,    36,    32,
      33,    34,     0,    35,    36,     0,    37,    38,    39,    40,
      41,    42,    37,    38,    39,    40,    41,    42,   111,   112,
       0,     0,     0,     0,   116,     0,    35,    36,     0,   120,
       0,     0,     0,     0,   124,    37,    38,    39,    40,    41,
      42
};

static const yytype_int8 yycheck[] =
{
      12,    42,     1,    18,    25,    46,    18,    19,    20,     3,
       4,     5,     6,    70,    26,    14,    25,    25,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    19,    41,    41,    18,    48,    45,    94,    47,    47,
      43,    43,     3,     4,     5,     6,     7,    46,     9,    10,
      41,    18,    46,    45,    15,    16,    17,    18,    19,    45,
      21,    41,    45,    41,    76,    18,     8,    28,     1,    -1,
      18,    19,    -1,    21,    -1,    87,    -1,    89,    -1,    -1,
      28,    -1,    43,    44,    45,    -1,    -1,    99,     3,     4,
       5,     6,     7,    41,     9,    10,    -1,    45,   110,    -1,
      15,    16,    17,    18,    19,    -1,    21,   119,     3,     4,
       5,     6,     7,    28,     9,    10,     3,     4,     5,     6,
      15,    16,    17,    18,    19,    -1,    21,    -1,    43,    44,
      45,    -1,    -1,    28,    18,    19,    -1,    21,    -1,     3,
       4,     5,     6,     7,    28,     9,    10,    -1,    43,    44,
      45,    15,    16,    17,    18,    19,    -1,    21,    -1,    -1,
      -1,    45,    -1,    -1,    28,    -1,    -1,    20,    21,    22,
      23,    24,     0,    26,    27,     3,     4,     5,     6,    43,
      -1,    45,    35,    36,    37,    38,    39,    40,    20,    21,
      22,    23,    24,    46,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    20,
      21,    22,    23,    24,    46,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      20,    21,    22,    23,    24,    46,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    20,    21,    22,    23,    24,    46,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    20,    21,    22,    23,    24,    -1,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    20,    21,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    20,    21,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    20,
      21,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    20,    21,    22,    23,    24,    -1,    26,    27,    22,
      23,    24,    -1,    26,    27,    -1,    35,    36,    37,    38,
      39,    40,    35,    36,    37,    38,    39,    40,   107,   108,
      -1,    -1,    -1,    -1,   113,    -1,    26,    27,    -1,   118,
      -1,    -1,    -1,    -1,   123,    35,    36,    37,    38,    39,
      40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    83,     0,     3,     4,     5,     6,    84,    85,    86,
      88,    18,    25,    41,    45,    47,    18,    19,    21,    28,
      45,   105,    46,    86,    87,    19,    25,   105,   105,   105,
      20,    21,    22,    23,    24,    26,    27,    35,    36,    37,
      38,    39,    40,    41,    43,    18,    42,    46,    48,   105,
      46,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,    89,    86,    43,    41,    91,    18,
      90,     7,     9,    10,    15,    16,    17,    43,    44,    85,
      86,    92,    94,    98,   101,   105,    91,    45,    45,    45,
      41,    41,    41,   105,    93,    18,    41,    44,   105,    99,
     105,    41,    91,    46,   105,    41,    44,    95,    96,    46,
     102,    92,    92,   100,   105,     8,    92,    41,    97,   103,
      92,   105,    46,   104,    92
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    82,    83,    83,    84,    84,    85,    85,    85,    86,
      86,    86,    86,    87,    87,    89,    88,    90,    88,    91,
      91,    92,    92,    93,    92,    92,    92,    92,    92,    92,
      92,    92,    95,    94,    96,    97,    94,    99,   100,    98,
     102,   103,   104,   101,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     3,     5,     6,     1,
       1,     1,     1,     2,     4,     0,     8,     0,     9,     0,
       2,     2,     1,     0,     4,     1,     1,     1,     2,     2,
       2,     3,     0,     6,     0,     0,     9,     0,     0,     7,
       0,     0,     0,    12,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 6: /* var_declaration: type_specifier IDENTIFIER ';'  */
#line 112 "c_parser.y"
                                    {
        if (insert_symbol(sym_table, (yyvsp[-1].str_val), (yyvsp[-2].str_val), line_num, 0) == 0) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Variable '%s' already declared\n", line_num, (yyvsp[-1].str_val));
            semantic_error_count++;
        }
        free((yyvsp[-2].str_val));
        free((yyvsp[-1].str_val));
    }
#line 1379 "c_parser.tab.c"
    break;

  case 7: /* var_declaration: type_specifier IDENTIFIER '=' expression ';'  */
#line 120 "c_parser.y"
                                                   {
        if (insert_symbol(sym_table, (yyvsp[-3].str_val), (yyvsp[-4].str_val), line_num, 0) == 0) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Variable '%s' already declared\n", line_num, (yyvsp[-3].str_val));
            semantic_error_count++;
        }
        free((yyvsp[-4].str_val));
        free((yyvsp[-3].str_val));
        free((yyvsp[-1].str_val));
    }
#line 1393 "c_parser.tab.c"
    break;

  case 8: /* var_declaration: type_specifier IDENTIFIER '[' NUMBER ']' ';'  */
#line 129 "c_parser.y"
                                                   {
        if (insert_symbol(sym_table, (yyvsp[-4].str_val), (yyvsp[-5].str_val), line_num, 0) == 0) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Array '%s' already declared\n", line_num, (yyvsp[-4].str_val));
            semantic_error_count++;
        }
        free((yyvsp[-5].str_val));
        free((yyvsp[-4].str_val));
    }
#line 1406 "c_parser.tab.c"
    break;

  case 9: /* type_specifier: INT  */
#line 140 "c_parser.y"
          { (yyval.str_val) = strdup("int"); }
#line 1412 "c_parser.tab.c"
    break;

  case 10: /* type_specifier: FLOAT  */
#line 141 "c_parser.y"
            { (yyval.str_val) = strdup("float"); }
#line 1418 "c_parser.tab.c"
    break;

  case 11: /* type_specifier: CHAR  */
#line 142 "c_parser.y"
           { (yyval.str_val) = strdup("char"); }
#line 1424 "c_parser.tab.c"
    break;

  case 12: /* type_specifier: VOID  */
#line 143 "c_parser.y"
           { (yyval.str_val) = strdup("void"); }
#line 1430 "c_parser.tab.c"
    break;

  case 13: /* parameter_list: type_specifier IDENTIFIER  */
#line 147 "c_parser.y"
                                {
        /* Add parameter to symbol table */
        insert_symbol(sym_table, (yyvsp[0].str_val), (yyvsp[-1].str_val), line_num, 0);
        free((yyvsp[-1].str_val));
        free((yyvsp[0].str_val));
    }
#line 1441 "c_parser.tab.c"
    break;

  case 14: /* parameter_list: parameter_list ',' type_specifier IDENTIFIER  */
#line 153 "c_parser.y"
                                                   {
        /* Add parameter to symbol table */
        insert_symbol(sym_table, (yyvsp[0].str_val), (yyvsp[-1].str_val), line_num, 0);
        free((yyvsp[-1].str_val));
        free((yyvsp[0].str_val));
    }
#line 1452 "c_parser.tab.c"
    break;

  case 15: /* $@1: %empty  */
#line 162 "c_parser.y"
                                            {
        if (insert_symbol(sym_table, (yyvsp[-3].str_val), (yyvsp[-4].str_val), line_num, 1) == 0) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Function '%s' already declared\n", line_num, (yyvsp[-3].str_val));
            semantic_error_count++;
        }
        in_function = 1;
        enter_scope(sym_table);
        free((yyvsp[-4].str_val));
        free((yyvsp[-3].str_val));
    }
#line 1467 "c_parser.tab.c"
    break;

  case 16: /* function_declaration: type_specifier IDENTIFIER '(' ')' '{' $@1 statement_list '}'  */
#line 172 "c_parser.y"
                       {
        exit_scope(sym_table);
        in_function = 0;
    }
#line 1476 "c_parser.tab.c"
    break;

  case 17: /* $@2: %empty  */
#line 176 "c_parser.y"
                                                           {
        if (insert_symbol(sym_table, (yyvsp[-4].str_val), (yyvsp[-5].str_val), line_num, 1) == 0) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Function '%s' already declared\n", line_num, (yyvsp[-4].str_val));
            semantic_error_count++;
        }
        in_function = 1;
        enter_scope(sym_table);
        free((yyvsp[-5].str_val));
        free((yyvsp[-4].str_val));
    }
#line 1491 "c_parser.tab.c"
    break;

  case 18: /* function_declaration: type_specifier IDENTIFIER '(' parameter_list ')' '{' $@2 statement_list '}'  */
#line 186 "c_parser.y"
                       {
        exit_scope(sym_table);
        in_function = 0;
    }
#line 1500 "c_parser.tab.c"
    break;

  case 21: /* statement: expression ';'  */
#line 198 "c_parser.y"
                     {
        if ((yyvsp[-1].str_val)) free((yyvsp[-1].str_val));
    }
#line 1508 "c_parser.tab.c"
    break;

  case 23: /* $@3: %empty  */
#line 202 "c_parser.y"
          {
        enter_scope(sym_table);
    }
#line 1516 "c_parser.tab.c"
    break;

  case 24: /* statement: '{' $@3 statement_list '}'  */
#line 205 "c_parser.y"
                       {
        exit_scope(sym_table);
    }
#line 1524 "c_parser.tab.c"
    break;

  case 28: /* statement: BREAK ';'  */
#line 211 "c_parser.y"
                {
        if (!in_loop) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: 'break' statement not within a loop\n", line_num);
            semantic_error_count++;
        }
    }
#line 1535 "c_parser.tab.c"
    break;

  case 29: /* statement: CONTINUE ';'  */
#line 217 "c_parser.y"
                   {
        if (!in_loop) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: 'continue' statement not within a loop\n", line_num);
            semantic_error_count++;
        }
    }
#line 1546 "c_parser.tab.c"
    break;

  case 30: /* statement: RETURN ';'  */
#line 223 "c_parser.y"
                 {
        if (!in_function) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: 'return' statement outside function\n", line_num);
            semantic_error_count++;
        }
    }
#line 1557 "c_parser.tab.c"
    break;

  case 31: /* statement: RETURN expression ';'  */
#line 229 "c_parser.y"
                            {
        if (!in_function) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: 'return' statement outside function\n", line_num);
            semantic_error_count++;
        }
        if ((yyvsp[-1].str_val)) free((yyvsp[-1].str_val));
    }
#line 1569 "c_parser.tab.c"
    break;

  case 32: /* $@4: %empty  */
#line 261 "c_parser.y"
    {
        /* After condition: emit IF_FALSE to skip then-body if condition is false */
        int end_label = create_label(code_gen);
        emit_tac_if_false(code_gen, (yyvsp[-1].str_val), end_label, line_num);
        push_loop_labels(end_label, -1);
        free((yyvsp[-1].str_val));
    }
#line 1581 "c_parser.tab.c"
    break;

  case 33: /* if_statement: IF '(' expression ')' $@4 statement  */
#line 269 "c_parser.y"
    {
        /* After then-body: emit label for else-to-jump-to */
        int end_label, dummy;
        pop_loop_labels(&end_label, &dummy);
        emit_tac_label(code_gen, end_label, line_num);
    }
#line 1592 "c_parser.tab.c"
    break;

  case 34: /* $@5: %empty  */
#line 276 "c_parser.y"
    {
        /* If-else: after condition, emit IF_FALSE */
        int else_label = create_label(code_gen);
        int end_label = create_label(code_gen);
        emit_tac_if_false(code_gen, (yyvsp[-1].str_val), else_label, line_num);
        push_loop_labels(else_label, end_label);
        free((yyvsp[-1].str_val));
    }
#line 1605 "c_parser.tab.c"
    break;

  case 35: /* $@6: %empty  */
#line 285 "c_parser.y"
    {
        /* After then-body, before else: emit GOTO end and LABEL else */
        int else_label, end_label;
        pop_loop_labels(&else_label, &end_label);
        emit_tac_goto(code_gen, end_label, line_num);
        emit_tac_label(code_gen, else_label, line_num);
        push_loop_labels(else_label, end_label);
    }
#line 1618 "c_parser.tab.c"
    break;

  case 36: /* if_statement: IF '(' expression ')' $@5 statement ELSE $@6 statement  */
#line 294 "c_parser.y"
    {
        /* After else-body: emit label for end */
        int else_label, end_label;
        pop_loop_labels(&else_label, &end_label);
        emit_tac_label(code_gen, end_label, line_num);
    }
#line 1629 "c_parser.tab.c"
    break;

  case 37: /* $@7: %empty  */
#line 304 "c_parser.y"
    {
        in_loop++;
        int start_label = create_label(code_gen);
        int end_label = create_label(code_gen);
        emit_tac_label(code_gen, start_label, line_num);
        push_loop_labels(start_label, end_label);
    }
#line 1641 "c_parser.tab.c"
    break;

  case 38: /* $@8: %empty  */
#line 312 "c_parser.y"
    {
        /* After condition: emit IF_FALSE */
        int start_label, end_label;
        pop_loop_labels(&start_label, &end_label);
        emit_tac_if_false(code_gen, (yyvsp[-1].str_val), end_label, line_num);
        push_loop_labels(start_label, end_label);
        free((yyvsp[-1].str_val));
    }
#line 1654 "c_parser.tab.c"
    break;

  case 39: /* while_statement: WHILE '(' $@7 expression ')' $@8 statement  */
#line 320 "c_parser.y"
              {
        /* After body: emit GOTO start and LABEL end */
        in_loop--;
        int start_label, end_label;
        pop_loop_labels(&start_label, &end_label);
        emit_tac_goto(code_gen, start_label, line_num);
        emit_tac_label(code_gen, end_label, line_num);
    }
#line 1667 "c_parser.tab.c"
    break;

  case 40: /* $@9: %empty  */
#line 332 "c_parser.y"
    {
        int start_label = create_label(code_gen);
        int end_label = create_label(code_gen);
        emit_tac_label(code_gen, start_label, line_num);
        push_loop_labels(start_label, end_label);
        if ((yyvsp[-1].str_val)) free((yyvsp[-1].str_val));
    }
#line 1679 "c_parser.tab.c"
    break;

  case 41: /* $@10: %empty  */
#line 340 "c_parser.y"
    {
        /* After condition: emit IF_FALSE */
        int start_label, end_label;
        pop_loop_labels(&start_label, &end_label);
        emit_tac_if_false(code_gen, (yyvsp[-1].str_val), end_label, line_num);
        push_loop_labels(start_label, end_label);
        free((yyvsp[-1].str_val));
    }
#line 1692 "c_parser.tab.c"
    break;

  case 42: /* $@11: %empty  */
#line 349 "c_parser.y"
    {
        /* Store update expression for later */
        if ((yyvsp[-1].str_val)) free((yyvsp[-1].str_val));
    }
#line 1701 "c_parser.tab.c"
    break;

  case 43: /* for_statement: FOR '(' expression ';' $@9 expression ';' $@10 expression ')' $@11 statement  */
#line 353 "c_parser.y"
              {
        /* After body: emit GOTO start and LABEL end */
        int start_label, end_label;
        pop_loop_labels(&start_label, &end_label);
        emit_tac_goto(code_gen, start_label, line_num);
        emit_tac_label(code_gen, end_label, line_num);
    }
#line 1713 "c_parser.tab.c"
    break;

  case 44: /* expression: IDENTIFIER  */
#line 363 "c_parser.y"
                 {
        if (!lookup_symbol(sym_table, (yyvsp[0].str_val))) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Undeclared variable '%s'\n", line_num, (yyvsp[0].str_val));
            semantic_error_count++;
        }
        (yyval.str_val) = strdup((yyvsp[0].str_val));
        free((yyvsp[0].str_val));
    }
#line 1726 "c_parser.tab.c"
    break;

  case 45: /* expression: NUMBER  */
#line 371 "c_parser.y"
             {
        (yyval.str_val) = (char*)malloc(20);
        sprintf((yyval.str_val), "%d", (yyvsp[0].int_val));
    }
#line 1735 "c_parser.tab.c"
    break;

  case 46: /* expression: expression '+' expression  */
#line 375 "c_parser.y"
                                {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_ADD, (yyval.str_val), (yyvsp[-2].str_val), (yyvsp[0].str_val), line_num);
        free((yyvsp[-2].str_val));
        free((yyvsp[0].str_val));
    }
#line 1746 "c_parser.tab.c"
    break;

  case 47: /* expression: expression '-' expression  */
#line 381 "c_parser.y"
                                {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_SUB, (yyval.str_val), (yyvsp[-2].str_val), (yyvsp[0].str_val), line_num);
        free((yyvsp[-2].str_val));
        free((yyvsp[0].str_val));
    }
#line 1757 "c_parser.tab.c"
    break;

  case 48: /* expression: expression '*' expression  */
#line 387 "c_parser.y"
                                {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_MUL, (yyval.str_val), (yyvsp[-2].str_val), (yyvsp[0].str_val), line_num);
        free((yyvsp[-2].str_val));
        free((yyvsp[0].str_val));
    }
#line 1768 "c_parser.tab.c"
    break;

  case 49: /* expression: expression '/' expression  */
#line 393 "c_parser.y"
                                {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_DIV, (yyval.str_val), (yyvsp[-2].str_val), (yyvsp[0].str_val), line_num);
        free((yyvsp[-2].str_val));
        free((yyvsp[0].str_val));
    }
#line 1779 "c_parser.tab.c"
    break;

  case 50: /* expression: expression '%' expression  */
#line 399 "c_parser.y"
                                {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_MOD, (yyval.str_val), (yyvsp[-2].str_val), (yyvsp[0].str_val), line_num);
        free((yyvsp[-2].str_val));
        free((yyvsp[0].str_val));
    }
#line 1790 "c_parser.tab.c"
    break;

  case 51: /* expression: expression EQ_OP expression  */
#line 405 "c_parser.y"
                                  {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_EQ, (yyval.str_val), (yyvsp[-2].str_val), (yyvsp[0].str_val), line_num);
        free((yyvsp[-2].str_val));
        free((yyvsp[0].str_val));
    }
#line 1801 "c_parser.tab.c"
    break;

  case 52: /* expression: expression NE_OP expression  */
#line 411 "c_parser.y"
                                  {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_NE, (yyval.str_val), (yyvsp[-2].str_val), (yyvsp[0].str_val), line_num);
        free((yyvsp[-2].str_val));
        free((yyvsp[0].str_val));
    }
#line 1812 "c_parser.tab.c"
    break;

  case 53: /* expression: expression '<' expression  */
#line 417 "c_parser.y"
                                {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_LT, (yyval.str_val), (yyvsp[-2].str_val), (yyvsp[0].str_val), line_num);
        free((yyvsp[-2].str_val));
        free((yyvsp[0].str_val));
    }
#line 1823 "c_parser.tab.c"
    break;

  case 54: /* expression: expression '>' expression  */
#line 423 "c_parser.y"
                                {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_GT, (yyval.str_val), (yyvsp[-2].str_val), (yyvsp[0].str_val), line_num);
        free((yyvsp[-2].str_val));
        free((yyvsp[0].str_val));
    }
#line 1834 "c_parser.tab.c"
    break;

  case 55: /* expression: expression LE_OP expression  */
#line 429 "c_parser.y"
                                  {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_LE, (yyval.str_val), (yyvsp[-2].str_val), (yyvsp[0].str_val), line_num);
        free((yyvsp[-2].str_val));
        free((yyvsp[0].str_val));
    }
#line 1845 "c_parser.tab.c"
    break;

  case 56: /* expression: expression GE_OP expression  */
#line 435 "c_parser.y"
                                  {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_GE, (yyval.str_val), (yyvsp[-2].str_val), (yyvsp[0].str_val), line_num);
        free((yyvsp[-2].str_val));
        free((yyvsp[0].str_val));
    }
#line 1856 "c_parser.tab.c"
    break;

  case 57: /* expression: expression AND_OP expression  */
#line 441 "c_parser.y"
                                   {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_AND, (yyval.str_val), (yyvsp[-2].str_val), (yyvsp[0].str_val), line_num);
        free((yyvsp[-2].str_val));
        free((yyvsp[0].str_val));
    }
#line 1867 "c_parser.tab.c"
    break;

  case 58: /* expression: expression OR_OP expression  */
#line 447 "c_parser.y"
                                  {
        (yyval.str_val) = new_temp();
        emit_tac_binary(code_gen, TAC_OR, (yyval.str_val), (yyvsp[-2].str_val), (yyvsp[0].str_val), line_num);
        free((yyvsp[-2].str_val));
        free((yyvsp[0].str_val));
    }
#line 1878 "c_parser.tab.c"
    break;

  case 59: /* expression: '-' expression  */
#line 453 "c_parser.y"
                               {
        (yyval.str_val) = new_temp();
        emit_tac_unary(code_gen, TAC_NEG, (yyval.str_val), (yyvsp[0].str_val), line_num);
        free((yyvsp[0].str_val));
    }
#line 1888 "c_parser.tab.c"
    break;

  case 60: /* expression: '!' expression  */
#line 458 "c_parser.y"
                     {
        (yyval.str_val) = new_temp();
        emit_tac_unary(code_gen, TAC_NOT, (yyval.str_val), (yyvsp[0].str_val), line_num);
        free((yyvsp[0].str_val));
    }
#line 1898 "c_parser.tab.c"
    break;

  case 61: /* expression: '(' expression ')'  */
#line 463 "c_parser.y"
                         {
        (yyval.str_val) = (yyvsp[-1].str_val);
    }
#line 1906 "c_parser.tab.c"
    break;

  case 62: /* expression: IDENTIFIER '=' expression  */
#line 466 "c_parser.y"
                                {
        if (!lookup_symbol(sym_table, (yyvsp[-2].str_val))) {
            fprintf(stderr, "SEMANTIC ERROR at line %d: Undeclared variable '%s'\n", line_num, (yyvsp[-2].str_val));
            semantic_error_count++;
        }
        emit_tac_binary(code_gen, TAC_ASSIGN, (yyvsp[-2].str_val), (yyvsp[0].str_val), NULL, line_num);
        (yyval.str_val) = strdup((yyvsp[-2].str_val));
        free((yyvsp[-2].str_val));
        free((yyvsp[0].str_val));
    }
#line 1921 "c_parser.tab.c"
    break;


#line 1925 "c_parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 478 "c_parser.y"


