%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "A9_220101096_translator.h"
    #include "A9_220101096.tab.h"
    extern "C" int yylex();
    extern YYSTYPE yylval;
    extern int line;
    int line = 1;  
    extern string id;  // Make sure this is defined in your translator.cpp
%}
%option noyywrap
/* Regular Expressions */
DIGIT           [0-9]
NON_ZERO        [1-9]
LETTER          [a-zA-Z]
FLOAT_CONST     {DIGIT}+\.{DIGIT}*|\.{DIGIT}+
ESCAPE_SEQ      "\\b"|"\\v"|"\\\'"|"\\\""|"\\\?"|"\\\\"|"\\a"|"\\f"|"\\n"|"\\r"|"\\t"
C_CHAR          [^\'\\\n]|{ESCAPE_SEQ}
S_CHAR          [^\"\\\n]|{ESCAPE_SEQ}
CHAR_SEQ        {C_CHAR}{C_CHAR}*
STRING_SEQ      {S_CHAR}{S_CHAR}*
IDENTIFIER      ({LETTER}|"_")({LETTER}|{DIGIT}|"_")*
INT_CONST       {NON_ZERO}{DIGIT}*|"0"+
CHAR_CONST      \'{CHAR_SEQ}\'
STRING          \"{STRING_SEQ}\"|\"\"
COMMENT_LINE    "//".*
COMMENT_MULTI   "/*"([^*]|\*+[^/*])*\**(\*"/")?
WS              [ \t]
NEWLINE         [\n]
%%
{COMMENT_LINE}          { /* Ignore single line comments */ }
{COMMENT_MULTI}         { /* Ignore multi-line comments */ }
"integer"                { return INT; }
"float"                 { return FLOAT; }
"char"                  { return CHAR; }
"void"                  { return VOID; }
"if"                    { return IF; }
"do"                    {return DO;}
"else"                  { return ELSE; }
"while"                 { return WHILE; }
"return"                { return RETURN; }
"<="                    { return LTE; }
">="                    { return GTE; }
"=="                    { return EQ; }
"!="                    { return NEQ; }
"&&"                    { return AND; }
"||"                    { return OR; }
";"                     { return SEMICOLON; }
"["                     { return SQUARE_BRACKET_OPEN; }
"]"                     { return SQUARE_BRACKET_CLOSE; }
"("                     { return ROUND_BRACKET_OPEN; }
")"                     { return ROUND_BRACKET_CLOSE; }
"begin"                     { return CURLY_BRACKET_OPEN; }
"end"                     { return CURLY_BRACKET_CLOSE; }
"*"                     { return MUL; }
"+"                     { return ADD; }
"-"                     { return SUB; }
"/"                     { return DIV; }
"%"                     { return MOD; }
"&"                     { return BITWISE_AND; }
"|"                     { return BITWISE_OR; }
"^"                     { return BITWISE_XOR; }
"~"                     { return BITWISE_NOT; }
"!"                     { return EXCLAIM; }
"<"                     { return BIT_SL; }  /* Change from << to < */
">"                     { return BIT_SR; }  /* Change from >> to > */
","                     { return COMMA; }
"="                     { return ASSIGN; }
"?"                     { return QUESTION; }
":"                     { return COLON; }
{INT_CONST}             {
                            yylval.intval = atoi(yytext);
                            return INTEGER_CONSTANT;
                        }
{FLOAT_CONST}           {
                            yylval.floatval = atof(yytext);
                            return FLOAT_CONSTANT;
                        }
{CHAR_CONST}            {
                            yylval.char_value = strdup(yytext);
                            return CHARACTER_CONSTANT;
                        }
{IDENTIFIER}            {
                            id = string(yytext);  /* Use string conversion */
                            return IDENTIFIER;
                        }
{STRING}                {
                            yylval.char_value = strdup(yytext);
                            return STRING_LITERAL;
                        }
{WS}                    { /* Ignore whitespace */ }
{NEWLINE}               { line++; }
%%