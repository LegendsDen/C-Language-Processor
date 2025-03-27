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
#line 1 "A7_220101096.y"

#include <stdlib.h>
#include <stdio.h>
extern int yylex();
void yyerror(const char*);
extern int yylineno;
extern char* yytext;    

#line 80 "A7_220101096.tab.c"

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

#include "A7_220101096.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PTR = 3,                        /* PTR  */
  YYSYMBOL_EQ = 4,                         /* EQ  */
  YYSYMBOL_CURLY_BRACE_OPEN = 5,           /* CURLY_BRACE_OPEN  */
  YYSYMBOL_CURLY_BRACE_CLOSE = 6,          /* CURLY_BRACE_CLOSE  */
  YYSYMBOL_ROUND_BRACE_OPEN = 7,           /* ROUND_BRACE_OPEN  */
  YYSYMBOL_ROUND_BRACE_CLOSE = 8,          /* ROUND_BRACE_CLOSE  */
  YYSYMBOL_SQ_BRACE_OPEN = 9,              /* SQ_BRACE_OPEN  */
  YYSYMBOL_SQ_BRACE_CLOSE = 10,            /* SQ_BRACE_CLOSE  */
  YYSYMBOL_COLON = 11,                     /* COLON  */
  YYSYMBOL_SEMI_COLON = 12,                /* SEMI_COLON  */
  YYSYMBOL_QUESTION_MARK = 13,             /* QUESTION_MARK  */
  YYSYMBOL_EQ_OP = 14,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 15,                     /* NE_OP  */
  YYSYMBOL_LTE_OP = 16,                    /* LTE_OP  */
  YYSYMBOL_GTE_OP = 17,                    /* GTE_OP  */
  YYSYMBOL_AND_OP = 18,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 19,                     /* OR_OP  */
  YYSYMBOL_LSHIFT = 20,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 21,                    /* RSHIFT  */
  YYSYMBOL_INC = 22,                       /* INC  */
  YYSYMBOL_DEC = 23,                       /* DEC  */
  YYSYMBOL_LESS_THAN = 24,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 25,              /* GREATER_THAN  */
  YYSYMBOL_BITWISEAND = 26,                /* BITWISEAND  */
  YYSYMBOL_BITWISEOR = 27,                 /* BITWISEOR  */
  YYSYMBOL_BITWISEXOR = 28,                /* BITWISEXOR  */
  YYSYMBOL_STAR = 29,                      /* STAR  */
  YYSYMBOL_PLUS = 30,                      /* PLUS  */
  YYSYMBOL_MINUS = 31,                     /* MINUS  */
  YYSYMBOL_EXCLAMATION = 32,               /* EXCLAMATION  */
  YYSYMBOL_DIVIDE = 33,                    /* DIVIDE  */
  YYSYMBOL_PERCENTAGE = 34,                /* PERCENTAGE  */
  YYSYMBOL_COMMA = 35,                     /* COMMA  */
  YYSYMBOL_VOID = 36,                      /* VOID  */
  YYSYMBOL_CHAR = 37,                      /* CHAR  */
  YYSYMBOL_INTEGER = 38,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 39,                     /* FLOAT  */
  YYSYMBOL_CONST = 40,                     /* CONST  */
  YYSYMBOL_BOOL = 41,                      /* BOOL  */
  YYSYMBOL_DO = 42,                        /* DO  */
  YYSYMBOL_IF = 43,                        /* IF  */
  YYSYMBOL_ELSE = 44,                      /* ELSE  */
  YYSYMBOL_FOR = 45,                       /* FOR  */
  YYSYMBOL_RETURN = 46,                    /* RETURN  */
  YYSYMBOL_WHILE = 47,                     /* WHILE  */
  YYSYMBOL_IDENTIFIER = 48,                /* IDENTIFIER  */
  YYSYMBOL_INTEGER_CONSTANT = 49,          /* INTEGER_CONSTANT  */
  YYSYMBOL_CHARACTER_CONSTANT = 50,        /* CHARACTER_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 51,            /* STRING_LITERAL  */
  YYSYMBOL_FLOAT_CONSTANT = 52,            /* FLOAT_CONSTANT  */
  YYSYMBOL_INVALID_TOKEN = 53,             /* INVALID_TOKEN  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_primary_expression = 55,        /* primary_expression  */
  YYSYMBOL_unary_expression = 56,          /* unary_expression  */
  YYSYMBOL_postfix_expression = 57,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 58,  /* argument_expression_list  */
  YYSYMBOL_unary_operator = 59,            /* unary_operator  */
  YYSYMBOL_60_1 = 60,                      /* $@1  */
  YYSYMBOL_61_2 = 61,                      /* $@2  */
  YYSYMBOL_multiplicative_expression = 62, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 63,       /* additive_expression  */
  YYSYMBOL_relational_expression = 64,     /* relational_expression  */
  YYSYMBOL_equality_expression = 65,       /* equality_expression  */
  YYSYMBOL_and_expression = 66,            /* and_expression  */
  YYSYMBOL_or_expression = 67,             /* or_expression  */
  YYSYMBOL_xor_expression = 68,            /* xor_expression  */
  YYSYMBOL_logical_AND_expression = 69,    /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 70,     /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 71,    /* conditional_expression  */
  YYSYMBOL_assignment_expression = 72,     /* assignment_expression  */
  YYSYMBOL_shift_expression = 73,          /* shift_expression  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_expression_opt = 75,            /* expression_opt  */
  YYSYMBOL_declaration = 76,               /* declaration  */
  YYSYMBOL_init_declarator = 77,           /* init_declarator  */
  YYSYMBOL_type_specifier = 78,            /* type_specifier  */
  YYSYMBOL_declarator = 79,                /* declarator  */
  YYSYMBOL_direct_declarator = 80,         /* direct_declarator  */
  YYSYMBOL_pointer = 81,                   /* pointer  */
  YYSYMBOL_pointer_opt = 82,               /* pointer_opt  */
  YYSYMBOL_parameter_list_opt = 83,        /* parameter_list_opt  */
  YYSYMBOL_parameter_list = 84,            /* parameter_list  */
  YYSYMBOL_identifier_opt = 85,            /* identifier_opt  */
  YYSYMBOL_parameter_declaration = 86,     /* parameter_declaration  */
  YYSYMBOL_initializer = 87,               /* initializer  */
  YYSYMBOL_statement = 88,                 /* statement  */
  YYSYMBOL_compound_statement = 89,        /* compound_statement  */
  YYSYMBOL_block_item_list_opt = 90,       /* block_item_list_opt  */
  YYSYMBOL_block_item_list = 91,           /* block_item_list  */
  YYSYMBOL_block_item = 92,                /* block_item  */
  YYSYMBOL_expression_statement = 93,      /* expression_statement  */
  YYSYMBOL_selection_statement = 94,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 95,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 96,            /* jump_statement  */
  YYSYMBOL_translation_units = 97,         /* translation_units  */
  YYSYMBOL_translation_unit = 98,          /* translation_unit  */
  YYSYMBOL_function_definition = 99        /* function_definition  */
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
typedef yytype_uint8 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   279

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    45,    45,    46,    47,    48,    49,    50,    54,    55,
      56,    57,    61,    62,    63,    64,    65,    66,    67,    72,
      73,    79,    80,    79,    82,    83,    84,    85,    89,    90,
      91,    92,    96,    97,    98,   102,   103,   104,   105,   106,
     110,   111,   112,   116,   117,   121,   122,   126,   127,   131,
     132,   136,   137,   141,   142,   146,   147,   148,   152,   153,
     154,   158,   162,   163,   167,   171,   172,   176,   177,   178,
     179,   180,   181,   182,   187,   191,   192,   193,   194,   198,
     203,   204,   208,   209,   213,   214,   218,   219,   223,   227,
     231,   232,   233,   234,   235,   239,   243,   244,   248,   249,
     253,   254,   258,   262,   263,   268,   270,   272,   277,   281,
     282,   285,   286,   290
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PTR", "EQ",
  "CURLY_BRACE_OPEN", "CURLY_BRACE_CLOSE", "ROUND_BRACE_OPEN",
  "ROUND_BRACE_CLOSE", "SQ_BRACE_OPEN", "SQ_BRACE_CLOSE", "COLON",
  "SEMI_COLON", "QUESTION_MARK", "EQ_OP", "NE_OP", "LTE_OP", "GTE_OP",
  "AND_OP", "OR_OP", "LSHIFT", "RSHIFT", "INC", "DEC", "LESS_THAN",
  "GREATER_THAN", "BITWISEAND", "BITWISEOR", "BITWISEXOR", "STAR", "PLUS",
  "MINUS", "EXCLAMATION", "DIVIDE", "PERCENTAGE", "COMMA", "VOID", "CHAR",
  "INTEGER", "FLOAT", "CONST", "BOOL", "DO", "IF", "ELSE", "FOR", "RETURN",
  "WHILE", "IDENTIFIER", "INTEGER_CONSTANT", "CHARACTER_CONSTANT",
  "STRING_LITERAL", "FLOAT_CONSTANT", "INVALID_TOKEN", "$accept",
  "primary_expression", "unary_expression", "postfix_expression",
  "argument_expression_list", "unary_operator", "$@1", "$@2",
  "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "and_expression",
  "or_expression", "xor_expression", "logical_AND_expression",
  "logical_OR_expression", "conditional_expression",
  "assignment_expression", "shift_expression", "expression",
  "expression_opt", "declaration", "init_declarator", "type_specifier",
  "declarator", "direct_declarator", "pointer", "pointer_opt",
  "parameter_list_opt", "parameter_list", "identifier_opt",
  "parameter_declaration", "initializer", "statement",
  "compound_statement", "block_item_list_opt", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "translation_units",
  "translation_unit", "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-81)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-98)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     151,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -22,
      29,   -81,   -81,   -81,    -3,    68,   -81,   -37,   -81,   -81,
     -81,   216,   131,   -81,   -81,     1,   216,   216,   216,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
      28,    34,   216,    19,    15,    14,    60,    24,    -4,    30,
      43,    21,   -81,   -81,    56,   -81,   227,    40,    57,   216,
      76,   -81,   -81,    74,   -81,   -22,   -81,   -81,    97,   179,
     -81,   -81,   -81,   -81,   -81,   151,    -5,   103,   -81,   -81,
      85,   216,    65,   100,   216,   -81,   -81,   -81,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   227,    70,   216,
     216,   106,   216,   -81,   111,   -81,   -81,   -22,   112,    84,
     -81,   -81,   114,   -81,   -81,   -81,   -81,   -81,    -2,   -81,
     115,   -81,   -81,   -81,   -81,    19,    19,    49,    49,    49,
      49,    49,    14,    14,    60,    24,    -4,    30,   116,    43,
      49,    49,   127,   132,   133,   -81,   135,    96,   -81,   151,
     -81,   118,   -81,   216,   -81,   216,   216,   227,   216,   227,
     -81,   -81,   -81,   -81,   -81,   -81,   139,   120,   143,   -81,
     144,   227,   216,   -81,   -81,   150,   227,   -81
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    67,    68,    69,    70,    71,    72,    73,   112,    81,
       0,   109,   111,    79,     0,    65,    80,     0,     1,   110,
      64,     0,    63,   113,    75,    74,     0,     0,     0,    21,
      24,    25,    26,    27,     2,     3,     4,     5,     6,    12,
      28,     8,     0,    32,    35,    40,    43,    45,    47,    49,
      51,    53,    55,    89,    56,    66,    63,     0,     0,    63,
       0,    61,    62,     0,   100,    81,   101,    90,     0,    63,
      98,    91,    92,    93,    94,    83,     0,     0,    10,    11,
       0,     0,     0,     0,     0,    13,    14,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,     0,     0,
      63,     0,     0,   102,    65,    95,    99,    81,     0,    82,
      84,    77,     0,     7,    22,    57,    18,    17,     0,    19,
       0,    29,    30,    31,    28,    33,    34,    38,    39,    36,
      37,    35,    41,    42,    44,    46,    48,    50,     0,    52,
      59,    60,     0,     0,     0,   108,     0,    87,    78,     0,
      76,     0,    16,     0,    15,     0,     0,    63,    63,    63,
      86,    88,    85,    23,    20,    54,     0,   103,     0,   106,
       0,    63,    63,   107,   104,     0,    63,   105
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -81,   -81,     0,   -81,   -81,   -81,   -81,   -81,   -10,   -80,
      12,    67,    59,    93,    73,    91,   -81,    31,   -21,   -81,
     -25,   -47,   -18,   -81,   -20,   134,   -81,   -81,    80,   -81,
     -81,   -81,    39,   -81,   -53,   185,   -81,   -81,   137,   -81,
     -81,   -81,   -81,   -81,   193,   -81
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    39,    40,    41,   128,    42,    80,   161,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    61,    54,
      62,    63,     8,    14,     9,    15,    25,    16,    17,   118,
     119,   171,   120,    55,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    10,    11,    12
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    77,    65,   108,    64,   121,   162,    13,    75,    20,
      76,    24,   111,   137,   138,   139,   140,   141,   141,   141,
     141,   141,   141,   100,   141,   150,   151,    78,    79,    18,
      93,    94,    81,   163,   103,   -58,   -58,    82,    95,    96,
     104,    83,    87,    84,   122,    91,    92,   109,    88,    65,
      99,    64,    89,    90,   108,   117,    85,    86,   101,   130,
     125,   102,   129,   154,   110,     1,     2,     3,     4,     5,
       6,     7,    21,    22,    97,    98,   105,   106,   148,    91,
      92,   135,   136,   112,   153,   141,   113,   156,   131,   132,
     133,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   115,   134,   134,   134,    26,   127,   142,
     143,   123,   124,   126,   177,    21,   179,   152,   155,   159,
     158,   178,    27,    28,   160,   164,    29,   165,   184,    30,
      31,    32,    33,   187,   166,   185,    22,   -97,    26,   117,
     167,   176,   174,   169,   170,   168,   173,   180,    34,    35,
      36,    37,    38,    27,    28,   182,   183,    29,   186,   145,
      30,    31,    32,    33,   181,   134,   144,     1,     2,     3,
       4,     5,     6,    56,    57,   147,    58,    59,    60,    34,
      35,    36,    37,    38,    22,   -96,    26,     1,     2,     3,
       4,     5,     6,     7,   146,   149,   175,   157,   172,   114,
      23,    27,    28,    19,     0,    29,   116,     0,    30,    31,
      32,    33,     0,     0,     0,     1,     2,     3,     4,     5,
       6,    56,    57,    26,    58,    59,    60,    34,    35,    36,
      37,    38,    22,     0,    26,     0,     0,     0,    27,    28,
       0,     0,    29,     0,     0,    30,    31,    32,    33,    27,
      28,     0,     0,    29,     0,     0,    30,    31,    32,    33,
       0,     0,     0,     0,    34,    35,    36,    37,    38,   107,
      57,     0,    58,    59,    60,    34,    35,    36,    37,    38
};

static const yytype_int16 yycheck[] =
{
      21,    26,    22,    56,    22,    10,     8,    29,     7,    12,
       9,    48,    59,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    27,   104,   105,   106,    27,    28,     0,
      16,    17,     4,    35,    13,    20,    21,     3,    24,    25,
      19,     7,    42,     9,    49,    30,    31,     7,    29,    69,
      26,    69,    33,    34,   107,    75,    22,    23,    28,    84,
      81,    18,    83,   110,     7,    36,    37,    38,    39,    40,
      41,    42,     4,     5,    14,    15,    20,    21,   103,    30,
      31,    91,    92,     7,   109,   165,    12,   112,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,     6,   104,   105,   106,     7,     8,    97,
      98,     8,    27,    48,   167,     4,   169,    47,    12,    35,
       8,   168,    22,    23,    10,    10,    26,    11,   181,    29,
      30,    31,    32,   186,     7,   182,     5,     6,     7,   159,
       8,   166,   163,     8,    48,    12,    28,     8,    48,    49,
      50,    51,    52,    22,    23,    12,    12,    26,     8,   100,
      29,    30,    31,    32,    44,   165,    99,    36,    37,    38,
      39,    40,    41,    42,    43,   102,    45,    46,    47,    48,
      49,    50,    51,    52,     5,     6,     7,    36,    37,    38,
      39,    40,    41,    42,   101,   104,   165,   117,   159,    65,
      15,    22,    23,    10,    -1,    26,    69,    -1,    29,    30,
      31,    32,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,     7,    45,    46,    47,    48,    49,    50,
      51,    52,     5,    -1,     7,    -1,    -1,    -1,    22,    23,
      -1,    -1,    26,    -1,    -1,    29,    30,    31,    32,    22,
      23,    -1,    -1,    26,    -1,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    42,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    37,    38,    39,    40,    41,    42,    76,    78,
      97,    98,    99,    29,    77,    79,    81,    82,     0,    98,
      12,     4,     5,    89,    48,    80,     7,    22,    23,    26,
      29,    30,    31,    32,    48,    49,    50,    51,    52,    55,
      56,    57,    59,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    87,    42,    43,    45,    46,
      47,    72,    74,    75,    76,    78,    88,    89,    90,    91,
      92,    93,    94,    95,    96,     7,     9,    74,    56,    56,
      60,     4,     3,     7,     9,    22,    23,    56,    29,    33,
      34,    30,    31,    16,    17,    24,    25,    14,    15,    26,
      27,    28,    18,    13,    19,    20,    21,    42,    88,     7,
       7,    75,     7,    12,    79,     6,    92,    78,    83,    84,
      86,    10,    49,     8,    27,    72,    48,     8,    58,    72,
      74,    56,    56,    56,    56,    62,    62,    63,    63,    63,
      63,    63,    64,    64,    65,    66,    67,    68,    74,    69,
      63,    63,    47,    74,    75,    12,    74,    82,     8,    35,
      10,    61,     8,    35,    10,    11,     7,     8,    12,     8,
      48,    85,    86,    28,    72,    71,    74,    88,    75,    88,
       8,    44,    12,    12,    88,    75,     8,    88
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    55,    55,    55,    55,    56,    56,
      56,    56,    57,    57,    57,    57,    57,    57,    57,    58,
      58,    60,    61,    59,    59,    59,    59,    59,    62,    62,
      62,    62,    63,    63,    63,    64,    64,    64,    64,    64,
      65,    65,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    72,    73,    73,
      73,    74,    75,    75,    76,    77,    77,    78,    78,    78,
      78,    78,    78,    78,    79,    80,    80,    80,    80,    81,
      82,    82,    83,    83,    84,    84,    85,    85,    86,    87,
      88,    88,    88,    88,    88,    89,    90,    90,    91,    91,
      92,    92,    93,    94,    94,    95,    95,    95,    96,    97,
      97,    98,    98,    99
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     2,
       2,     2,     1,     2,     2,     4,     4,     3,     3,     1,
       3,     0,     0,     5,     1,     1,     1,     1,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     1,     3,     1,     3,
       3,     1,     1,     0,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     4,     3,     4,     1,
       1,     0,     1,     0,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     1,     3,     1,     0,     1,     2,
       1,     1,     2,     5,     7,     9,     5,     7,     3,     1,
       2,     1,     1,     3
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* primary_expression: IDENTIFIER  */
#line 45 "A7_220101096.y"
                                                        {printf("IDENTIFIER to primary_expression.\n");}
#line 1599 "A7_220101096.tab.c"
    break;

  case 3: /* primary_expression: INTEGER_CONSTANT  */
#line 46 "A7_220101096.y"
                                                        {printf("INTEGER_CONSTANT to primary_expression.\n");}
#line 1605 "A7_220101096.tab.c"
    break;

  case 4: /* primary_expression: CHARACTER_CONSTANT  */
#line 47 "A7_220101096.y"
                                                        {printf("CHARACTER_CONSTANT to primary_expression.\n");}
#line 1611 "A7_220101096.tab.c"
    break;

  case 5: /* primary_expression: STRING_LITERAL  */
#line 48 "A7_220101096.y"
                                                        {printf("STRING LITERAL to primary_expression.\n");}
#line 1617 "A7_220101096.tab.c"
    break;

  case 6: /* primary_expression: FLOAT_CONSTANT  */
#line 49 "A7_220101096.y"
                                                        {printf("FLOAT_CONSTANT to primary_expression.\n");}
#line 1623 "A7_220101096.tab.c"
    break;

  case 7: /* primary_expression: ROUND_BRACE_OPEN expression ROUND_BRACE_CLOSE  */
#line 50 "A7_220101096.y"
                                                        {printf("(expression) to primary_expression.\n");}
#line 1629 "A7_220101096.tab.c"
    break;

  case 8: /* unary_expression: postfix_expression  */
#line 54 "A7_220101096.y"
                                      { printf("postfix_expression to unary_expression.\n"); }
#line 1635 "A7_220101096.tab.c"
    break;

  case 9: /* unary_expression: unary_operator unary_expression  */
#line 55 "A7_220101096.y"
                                            { printf("unary_operator unary_expression to unary_expression.\n"); }
#line 1641 "A7_220101096.tab.c"
    break;

  case 10: /* unary_expression: INC unary_expression  */
#line 56 "A7_220101096.y"
                                            { printf("Pre-increment (++x) detected.\n"); }
#line 1647 "A7_220101096.tab.c"
    break;

  case 11: /* unary_expression: DEC unary_expression  */
#line 57 "A7_220101096.y"
                                            { printf("Pre-decrement (--x) detected.\n"); }
#line 1653 "A7_220101096.tab.c"
    break;

  case 12: /* postfix_expression: primary_expression  */
#line 61 "A7_220101096.y"
                                             { printf("primary_expression to postfix_expression.\n"); }
#line 1659 "A7_220101096.tab.c"
    break;

  case 13: /* postfix_expression: postfix_expression INC  */
#line 62 "A7_220101096.y"
                                             { printf("Post-increment (x++) detected.\n"); }
#line 1665 "A7_220101096.tab.c"
    break;

  case 14: /* postfix_expression: postfix_expression DEC  */
#line 63 "A7_220101096.y"
                                             { printf("Post-decrement (x--) detected.\n"); }
#line 1671 "A7_220101096.tab.c"
    break;

  case 15: /* postfix_expression: postfix_expression SQ_BRACE_OPEN expression SQ_BRACE_CLOSE  */
#line 64 "A7_220101096.y"
                                                                 { printf("[expression] to postfix_expression.\n"); }
#line 1677 "A7_220101096.tab.c"
    break;

  case 16: /* postfix_expression: postfix_expression ROUND_BRACE_OPEN argument_expression_list ROUND_BRACE_CLOSE  */
#line 65 "A7_220101096.y"
                                                                                     { printf("(argument_expression_list) to postfix_expression.\n"); }
#line 1683 "A7_220101096.tab.c"
    break;

  case 17: /* postfix_expression: postfix_expression ROUND_BRACE_OPEN ROUND_BRACE_CLOSE  */
#line 66 "A7_220101096.y"
                                                            { printf("() to postfix_expression.\n"); }
#line 1689 "A7_220101096.tab.c"
    break;

  case 18: /* postfix_expression: postfix_expression PTR IDENTIFIER  */
#line 67 "A7_220101096.y"
                                             { printf("IDENTIFIER to postfix_expression.\n"); }
#line 1695 "A7_220101096.tab.c"
    break;

  case 19: /* argument_expression_list: assignment_expression  */
#line 72 "A7_220101096.y"
                                                                {printf("assignment_expression to argument_expression_list.\n");}
#line 1701 "A7_220101096.tab.c"
    break;

  case 20: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 73 "A7_220101096.y"
                                                                {printf("argument_expression_list, assignment_expression to argument_expression_list.\n");}
#line 1707 "A7_220101096.tab.c"
    break;

  case 21: /* $@1: %empty  */
#line 79 "A7_220101096.y"
                    {printf("& to unary_operator.\n");}
#line 1713 "A7_220101096.tab.c"
    break;

  case 22: /* $@2: %empty  */
#line 80 "A7_220101096.y"
                   {printf("| to unary_operator.\n");}
#line 1719 "A7_220101096.tab.c"
    break;

  case 23: /* unary_operator: BITWISEAND $@1 BITWISEOR $@2 BITWISEXOR  */
#line 81 "A7_220101096.y"
                    {printf("^ to unary_operator.\n");}
#line 1725 "A7_220101096.tab.c"
    break;

  case 24: /* unary_operator: STAR  */
#line 82 "A7_220101096.y"
                    {printf("* to unary_operator.\n");}
#line 1731 "A7_220101096.tab.c"
    break;

  case 25: /* unary_operator: PLUS  */
#line 83 "A7_220101096.y"
                    {printf("+ to unary_operator.\n");}
#line 1737 "A7_220101096.tab.c"
    break;

  case 26: /* unary_operator: MINUS  */
#line 84 "A7_220101096.y"
                    {printf("- to unary operator.\n");}
#line 1743 "A7_220101096.tab.c"
    break;

  case 27: /* unary_operator: EXCLAMATION  */
#line 85 "A7_220101096.y"
                    {printf("! to unary_operator.\n");}
#line 1749 "A7_220101096.tab.c"
    break;

  case 28: /* multiplicative_expression: unary_expression  */
#line 89 "A7_220101096.y"
                                                                {printf("unary_expression to multiplicative_expression.\n");}
#line 1755 "A7_220101096.tab.c"
    break;

  case 29: /* multiplicative_expression: multiplicative_expression STAR unary_expression  */
#line 90 "A7_220101096.y"
                                                                {printf("multiplicative_expression * unary_expression to multiplicative expression.\n");}
#line 1761 "A7_220101096.tab.c"
    break;

  case 30: /* multiplicative_expression: multiplicative_expression DIVIDE unary_expression  */
#line 91 "A7_220101096.y"
                                                                {printf("multiplicative_expression / unary_expression to multiplicative_expression.\n");}
#line 1767 "A7_220101096.tab.c"
    break;

  case 31: /* multiplicative_expression: multiplicative_expression PERCENTAGE unary_expression  */
#line 92 "A7_220101096.y"
                                                                {printf("multiplicative_expression modulo unary_expression to multiplicative_expression.\n");}
#line 1773 "A7_220101096.tab.c"
    break;

  case 32: /* additive_expression: multiplicative_expression  */
#line 96 "A7_220101096.y"
                                                                {printf("multiplicative_expression to additive_expression.\n");}
#line 1779 "A7_220101096.tab.c"
    break;

  case 33: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 97 "A7_220101096.y"
                                                                {printf("additive_expression + multiplicative_expression to additive_expression.\n");}
#line 1785 "A7_220101096.tab.c"
    break;

  case 34: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 98 "A7_220101096.y"
                                                                {printf("additive_expression - multiplicative_expression to additive_expression.\n");}
#line 1791 "A7_220101096.tab.c"
    break;

  case 35: /* relational_expression: additive_expression  */
#line 102 "A7_220101096.y"
                                                                    {printf("additive_expression to relational_expression.\n");}
#line 1797 "A7_220101096.tab.c"
    break;

  case 36: /* relational_expression: relational_expression LESS_THAN additive_expression  */
#line 103 "A7_220101096.y"
                                                                    {printf("relational_expression < additive_expression to relational_expression.\n");}
#line 1803 "A7_220101096.tab.c"
    break;

  case 37: /* relational_expression: relational_expression GREATER_THAN additive_expression  */
#line 104 "A7_220101096.y"
                                                                    {printf("relational_expression > additive_expression to relational_expression.\n");}
#line 1809 "A7_220101096.tab.c"
    break;

  case 38: /* relational_expression: relational_expression LTE_OP additive_expression  */
#line 105 "A7_220101096.y"
                                                                    {printf("relational_expression <= additive_expression to relational_expression.\n");}
#line 1815 "A7_220101096.tab.c"
    break;

  case 39: /* relational_expression: relational_expression GTE_OP additive_expression  */
#line 106 "A7_220101096.y"
                                                                    {printf("relational_expression >= additive_expression to relational_expression.\n");}
#line 1821 "A7_220101096.tab.c"
    break;

  case 40: /* equality_expression: relational_expression  */
#line 110 "A7_220101096.y"
                                                            {printf("relational_expression to equality_expression.\n");}
#line 1827 "A7_220101096.tab.c"
    break;

  case 41: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 111 "A7_220101096.y"
                                                            {printf("equality_expression == relational_expression to equality_expression.\n");}
#line 1833 "A7_220101096.tab.c"
    break;

  case 42: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 112 "A7_220101096.y"
                                                            {printf("equality_expression != relational_expression to equality_expression.\n");}
#line 1839 "A7_220101096.tab.c"
    break;

  case 43: /* and_expression: equality_expression  */
#line 116 "A7_220101096.y"
                                                            { printf("equality_expression to and_expression.\n"); }
#line 1845 "A7_220101096.tab.c"
    break;

  case 44: /* and_expression: and_expression BITWISEAND equality_expression  */
#line 117 "A7_220101096.y"
                                                            { printf("and_expression & equality_expression to and_expression.\n"); }
#line 1851 "A7_220101096.tab.c"
    break;

  case 45: /* or_expression: and_expression  */
#line 121 "A7_220101096.y"
                                                            { printf("and_expression to or_expression.\n"); }
#line 1857 "A7_220101096.tab.c"
    break;

  case 46: /* or_expression: or_expression BITWISEOR and_expression  */
#line 122 "A7_220101096.y"
                                                           { printf("or_expression | and_expression to or_expression.\n"); }
#line 1863 "A7_220101096.tab.c"
    break;

  case 47: /* xor_expression: or_expression  */
#line 126 "A7_220101096.y"
                                                           { printf("or_expression to xor_expression.\n"); }
#line 1869 "A7_220101096.tab.c"
    break;

  case 48: /* xor_expression: xor_expression BITWISEXOR or_expression  */
#line 127 "A7_220101096.y"
                                                          { printf("xor_expression ^ or_expression to xor_expression.\n"); }
#line 1875 "A7_220101096.tab.c"
    break;

  case 49: /* logical_AND_expression: xor_expression  */
#line 131 "A7_220101096.y"
                                                           { printf("xor_expression to logical_AND_expression.\n"); }
#line 1881 "A7_220101096.tab.c"
    break;

  case 50: /* logical_AND_expression: logical_AND_expression AND_OP xor_expression  */
#line 132 "A7_220101096.y"
                                                          { printf("logical_AND_expression && xor_expression to logical_AND_expression.\n"); }
#line 1887 "A7_220101096.tab.c"
    break;

  case 51: /* logical_OR_expression: logical_AND_expression  */
#line 136 "A7_220101096.y"
                                                          { printf("logical_AND_expression to logical_OR_expression.\n"); }
#line 1893 "A7_220101096.tab.c"
    break;

  case 52: /* logical_OR_expression: logical_OR_expression OR_OP logical_AND_expression  */
#line 137 "A7_220101096.y"
                                                         { printf("logical_OR_expression || logical_AND_expression to logical_OR_expression.\n"); }
#line 1899 "A7_220101096.tab.c"
    break;

  case 53: /* conditional_expression: logical_OR_expression  */
#line 141 "A7_220101096.y"
                                                                                        {printf("logical_OR_expression to conditional_expression.\n");}
#line 1905 "A7_220101096.tab.c"
    break;

  case 54: /* conditional_expression: logical_OR_expression QUESTION_MARK expression COLON conditional_expression  */
#line 142 "A7_220101096.y"
                                                                                        {printf("logical_OR_expression ? expression : conditional_expression to conditional_expression.");}
#line 1911 "A7_220101096.tab.c"
    break;

  case 55: /* assignment_expression: conditional_expression  */
#line 146 "A7_220101096.y"
                                                            {printf("conditional_expression to assignment_expression.\n");}
#line 1917 "A7_220101096.tab.c"
    break;

  case 56: /* assignment_expression: shift_expression  */
#line 147 "A7_220101096.y"
                                                            {printf("shift_expression to assignment_expression.\n");}
#line 1923 "A7_220101096.tab.c"
    break;

  case 57: /* assignment_expression: unary_expression EQ assignment_expression  */
#line 148 "A7_220101096.y"
                                                            {printf("unary_expression = assignment_expression to assignment_expression.\n");}
#line 1929 "A7_220101096.tab.c"
    break;

  case 58: /* shift_expression: additive_expression  */
#line 152 "A7_220101096.y"
                                                       { printf("additive_expression to shift_expression.\n"); }
#line 1935 "A7_220101096.tab.c"
    break;

  case 59: /* shift_expression: shift_expression LSHIFT additive_expression  */
#line 153 "A7_220101096.y"
                                                      { printf("Left shift (<<) detected.\n"); }
#line 1941 "A7_220101096.tab.c"
    break;

  case 60: /* shift_expression: shift_expression RSHIFT additive_expression  */
#line 154 "A7_220101096.y"
                                                      { printf("Right shift (>>) detected.\n"); }
#line 1947 "A7_220101096.tab.c"
    break;

  case 61: /* expression: assignment_expression  */
#line 158 "A7_220101096.y"
                                {printf("assignment_expression to expression.\n");}
#line 1953 "A7_220101096.tab.c"
    break;

  case 64: /* declaration: type_specifier init_declarator SEMI_COLON  */
#line 167 "A7_220101096.y"
                                                    {printf("type_specifier init_declarator ; to declaration.\n");}
#line 1959 "A7_220101096.tab.c"
    break;

  case 65: /* init_declarator: declarator  */
#line 171 "A7_220101096.y"
                                    {printf("declarator to init_declarator.\n");}
#line 1965 "A7_220101096.tab.c"
    break;

  case 66: /* init_declarator: declarator EQ initializer  */
#line 172 "A7_220101096.y"
                                    {printf("assignment.\n");}
#line 1971 "A7_220101096.tab.c"
    break;

  case 67: /* type_specifier: VOID  */
#line 176 "A7_220101096.y"
                    {printf("type: void\n");}
#line 1977 "A7_220101096.tab.c"
    break;

  case 68: /* type_specifier: CHAR  */
#line 177 "A7_220101096.y"
                    {printf("type: char\n");}
#line 1983 "A7_220101096.tab.c"
    break;

  case 69: /* type_specifier: INTEGER  */
#line 178 "A7_220101096.y"
                    {printf("type: integer\n");}
#line 1989 "A7_220101096.tab.c"
    break;

  case 70: /* type_specifier: FLOAT  */
#line 179 "A7_220101096.y"
                    {printf("type: float\n");}
#line 1995 "A7_220101096.tab.c"
    break;

  case 71: /* type_specifier: CONST  */
#line 180 "A7_220101096.y"
                    {printf("type: const\n");}
#line 2001 "A7_220101096.tab.c"
    break;

  case 72: /* type_specifier: BOOL  */
#line 181 "A7_220101096.y"
                    {printf("type: bool\n");}
#line 2007 "A7_220101096.tab.c"
    break;

  case 73: /* type_specifier: DO  */
#line 182 "A7_220101096.y"
                    {printf("type: do\n");}
#line 2013 "A7_220101096.tab.c"
    break;

  case 74: /* declarator: pointer_opt direct_declarator  */
#line 187 "A7_220101096.y"
                                       {printf("pointer_opt direct_declarator to declarator.\n");}
#line 2019 "A7_220101096.tab.c"
    break;

  case 75: /* direct_declarator: IDENTIFIER  */
#line 191 "A7_220101096.y"
                                                                                    {printf("identifier to direct_declarator.\n");}
#line 2025 "A7_220101096.tab.c"
    break;

  case 76: /* direct_declarator: direct_declarator SQ_BRACE_OPEN INTEGER_CONSTANT SQ_BRACE_CLOSE  */
#line 192 "A7_220101096.y"
                                                                                    {printf("array declaration.\n");}
#line 2031 "A7_220101096.tab.c"
    break;

  case 77: /* direct_declarator: direct_declarator SQ_BRACE_OPEN SQ_BRACE_CLOSE  */
#line 193 "A7_220101096.y"
                                                      { printf("Array declaration without size.\n"); }
#line 2037 "A7_220101096.tab.c"
    break;

  case 78: /* direct_declarator: direct_declarator ROUND_BRACE_OPEN parameter_list_opt ROUND_BRACE_CLOSE  */
#line 194 "A7_220101096.y"
                                                                                    {printf("function declaration.\n");}
#line 2043 "A7_220101096.tab.c"
    break;

  case 79: /* pointer: STAR  */
#line 198 "A7_220101096.y"
                {printf("pointer.\n");}
#line 2049 "A7_220101096.tab.c"
    break;

  case 84: /* parameter_list: parameter_declaration  */
#line 213 "A7_220101096.y"
                                                        {printf("parameter_declaration to parameter_list.\n");}
#line 2055 "A7_220101096.tab.c"
    break;

  case 85: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 214 "A7_220101096.y"
                                                        {printf("parameter list extension.\n");}
#line 2061 "A7_220101096.tab.c"
    break;

  case 88: /* parameter_declaration: type_specifier pointer_opt identifier_opt  */
#line 223 "A7_220101096.y"
                                                    {printf("parameter_declaration.\n");}
#line 2067 "A7_220101096.tab.c"
    break;

  case 89: /* initializer: assignment_expression  */
#line 227 "A7_220101096.y"
                                {printf("assignment_expression to initializer.\n");}
#line 2073 "A7_220101096.tab.c"
    break;

  case 90: /* statement: compound_statement  */
#line 231 "A7_220101096.y"
                                {printf("compound_statement.\n");}
#line 2079 "A7_220101096.tab.c"
    break;

  case 91: /* statement: expression_statement  */
#line 232 "A7_220101096.y"
                                {printf("expression_statement.\n");}
#line 2085 "A7_220101096.tab.c"
    break;

  case 92: /* statement: selection_statement  */
#line 233 "A7_220101096.y"
                                {printf("selection_statement.\n");}
#line 2091 "A7_220101096.tab.c"
    break;

  case 93: /* statement: iteration_statement  */
#line 234 "A7_220101096.y"
                                {printf("iteration_statement.\n");}
#line 2097 "A7_220101096.tab.c"
    break;

  case 94: /* statement: jump_statement  */
#line 235 "A7_220101096.y"
                                {printf("jump_statement.\n");}
#line 2103 "A7_220101096.tab.c"
    break;

  case 95: /* compound_statement: CURLY_BRACE_OPEN block_item_list_opt CURLY_BRACE_CLOSE  */
#line 239 "A7_220101096.y"
                                                                   {printf("compound statement declaration.\n");}
#line 2109 "A7_220101096.tab.c"
    break;

  case 98: /* block_item_list: block_item  */
#line 248 "A7_220101096.y"
                                        {printf("block list.\n");}
#line 2115 "A7_220101096.tab.c"
    break;

  case 99: /* block_item_list: block_item_list block_item  */
#line 249 "A7_220101096.y"
                                        {printf("block list extension.\n");}
#line 2121 "A7_220101096.tab.c"
    break;

  case 100: /* block_item: declaration  */
#line 253 "A7_220101096.y"
                        {printf("block item declaration.\n");}
#line 2127 "A7_220101096.tab.c"
    break;

  case 101: /* block_item: statement  */
#line 254 "A7_220101096.y"
                        {printf("block item statement.\n");}
#line 2133 "A7_220101096.tab.c"
    break;

  case 102: /* expression_statement: expression_opt SEMI_COLON  */
#line 258 "A7_220101096.y"
                                      {printf("expression opt statement.\n");}
#line 2139 "A7_220101096.tab.c"
    break;

  case 103: /* selection_statement: IF ROUND_BRACE_OPEN expression ROUND_BRACE_CLOSE statement  */
#line 262 "A7_220101096.y"
                                                                                            {printf("if statement.\n");}
#line 2145 "A7_220101096.tab.c"
    break;

  case 104: /* selection_statement: IF ROUND_BRACE_OPEN expression ROUND_BRACE_CLOSE statement ELSE statement  */
#line 263 "A7_220101096.y"
                                                                                            {printf("if else statement.\n");}
#line 2151 "A7_220101096.tab.c"
    break;

  case 105: /* iteration_statement: FOR ROUND_BRACE_OPEN expression_opt SEMI_COLON expression_opt SEMI_COLON expression_opt ROUND_BRACE_CLOSE statement  */
#line 269 "A7_220101096.y"
        {printf("for loop.\n");}
#line 2157 "A7_220101096.tab.c"
    break;

  case 106: /* iteration_statement: WHILE ROUND_BRACE_OPEN expression ROUND_BRACE_CLOSE statement  */
#line 271 "A7_220101096.y"
        {printf("while loop.\n");}
#line 2163 "A7_220101096.tab.c"
    break;

  case 107: /* iteration_statement: DO statement WHILE ROUND_BRACE_OPEN expression ROUND_BRACE_CLOSE SEMI_COLON  */
#line 273 "A7_220101096.y"
        {printf("do-while loop.\n");}
#line 2169 "A7_220101096.tab.c"
    break;

  case 108: /* jump_statement: RETURN expression_opt SEMI_COLON  */
#line 277 "A7_220101096.y"
                                             {printf("return statement.\n");}
#line 2175 "A7_220101096.tab.c"
    break;

  case 109: /* translation_units: translation_unit  */
#line 281 "A7_220101096.y"
                                                {printf("first tr_unit -> units.\n");}
#line 2181 "A7_220101096.tab.c"
    break;

  case 110: /* translation_units: translation_units translation_unit  */
#line 282 "A7_220101096.y"
                                                {printf("another tr_unit read.\n");}
#line 2187 "A7_220101096.tab.c"
    break;

  case 111: /* translation_unit: function_definition  */
#line 285 "A7_220101096.y"
                                    {printf("function definition.\n");}
#line 2193 "A7_220101096.tab.c"
    break;

  case 112: /* translation_unit: declaration  */
#line 286 "A7_220101096.y"
                                    {printf("function declaration statement.\n");}
#line 2199 "A7_220101096.tab.c"
    break;

  case 113: /* function_definition: type_specifier declarator compound_statement  */
#line 290 "A7_220101096.y"
                                                            {printf("type specifier declarator.\n");}
#line 2205 "A7_220101096.tab.c"
    break;


#line 2209 "A7_220101096.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 306 "A7_220101096.y"


void yyerror(const char* s) {
    printf("ERROR [Line %d] : %s, unable to parse : %s\n", yylineno, s, yytext);
}
