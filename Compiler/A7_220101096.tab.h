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

#ifndef YY_YY_A7_220101096_TAB_H_INCLUDED
# define YY_YY_A7_220101096_TAB_H_INCLUDED
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
    PTR = 258,                     /* PTR  */
    EQ = 259,                      /* EQ  */
    CURLY_BRACE_OPEN = 260,        /* CURLY_BRACE_OPEN  */
    CURLY_BRACE_CLOSE = 261,       /* CURLY_BRACE_CLOSE  */
    ROUND_BRACE_OPEN = 262,        /* ROUND_BRACE_OPEN  */
    ROUND_BRACE_CLOSE = 263,       /* ROUND_BRACE_CLOSE  */
    SQ_BRACE_OPEN = 264,           /* SQ_BRACE_OPEN  */
    SQ_BRACE_CLOSE = 265,          /* SQ_BRACE_CLOSE  */
    COLON = 266,                   /* COLON  */
    SEMI_COLON = 267,              /* SEMI_COLON  */
    QUESTION_MARK = 268,           /* QUESTION_MARK  */
    EQ_OP = 269,                   /* EQ_OP  */
    NE_OP = 270,                   /* NE_OP  */
    LTE_OP = 271,                  /* LTE_OP  */
    GTE_OP = 272,                  /* GTE_OP  */
    AND_OP = 273,                  /* AND_OP  */
    OR_OP = 274,                   /* OR_OP  */
    LSHIFT = 275,                  /* LSHIFT  */
    RSHIFT = 276,                  /* RSHIFT  */
    INC = 277,                     /* INC  */
    DEC = 278,                     /* DEC  */
    LESS_THAN = 279,               /* LESS_THAN  */
    GREATER_THAN = 280,            /* GREATER_THAN  */
    BITWISEAND = 281,              /* BITWISEAND  */
    BITWISEOR = 282,               /* BITWISEOR  */
    BITWISEXOR = 283,              /* BITWISEXOR  */
    STAR = 284,                    /* STAR  */
    PLUS = 285,                    /* PLUS  */
    MINUS = 286,                   /* MINUS  */
    EXCLAMATION = 287,             /* EXCLAMATION  */
    DIVIDE = 288,                  /* DIVIDE  */
    PERCENTAGE = 289,              /* PERCENTAGE  */
    COMMA = 290,                   /* COMMA  */
    VOID = 291,                    /* VOID  */
    CHAR = 292,                    /* CHAR  */
    INTEGER = 293,                 /* INTEGER  */
    FLOAT = 294,                   /* FLOAT  */
    CONST = 295,                   /* CONST  */
    BOOL = 296,                    /* BOOL  */
    DO = 297,                      /* DO  */
    IF = 298,                      /* IF  */
    ELSE = 299,                    /* ELSE  */
    FOR = 300,                     /* FOR  */
    RETURN = 301,                  /* RETURN  */
    WHILE = 302,                   /* WHILE  */
    IDENTIFIER = 303,              /* IDENTIFIER  */
    INTEGER_CONSTANT = 304,        /* INTEGER_CONSTANT  */
    CHARACTER_CONSTANT = 305,      /* CHARACTER_CONSTANT  */
    STRING_LITERAL = 306,          /* STRING_LITERAL  */
    FLOAT_CONSTANT = 307,          /* FLOAT_CONSTANT  */
    INVALID_TOKEN = 308            /* INVALID_TOKEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_A7_220101096_TAB_H_INCLUDED  */
