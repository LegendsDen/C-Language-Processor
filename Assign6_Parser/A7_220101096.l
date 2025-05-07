%{
    #include <stdio.h>
    #include <stdlib.h>
   #include "A7_220101096.tab.h"
   extern void yyerror(char*);


    // Define maximum symbols
    #define MAX_SYMBOLS 1000

    // Symbol Table Structure
    typedef struct {
        char name[100];
        char type[20];
    } Symbol;

    Symbol symbolTable[MAX_SYMBOLS];
    int symbolCount = 0;

    void addToSymbolTable(const char* name, const char* type) {
        for (int i = 0; i < symbolCount; i++) {
            if (strcmp(symbolTable[i].name, name) == 0)
                return; // Avoid duplicates
        }
        strcpy(symbolTable[symbolCount].name, name);
        strcpy(symbolTable[symbolCount].type, type);
        symbolCount++;
    }

    // Function to print symbol table to a file
    void print_symbol_table() {
        FILE *symbol_file = fopen("symbol_table.txt", "w");
        fprintf(symbol_file, "-----------------------------------\n");
        fprintf(symbol_file, "SYMBOL TABLE\n----------------\n");
        for (int i = 0; i < symbolCount; i++) {
            fprintf(symbol_file, "%-20s : %s\n", symbolTable[i].name, symbolTable[i].type);
        }

        fprintf(symbol_file, "-----------------------------------\n");
        fclose(symbol_file);
    }
%}


%x MULTI_LINE_FLAG
%x SINGLE_LINE_FLAG

IDENTIFIER              [A-Za-z_][A-Za-z0-9_]*
ESCAPE_SEQUENCE         "\\\'"|"\\\""|"\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"  

DIGIT                   [0-9]
DIGIT_SEQ               [0-9]+
NONZERO_DIGIT           [1-9]
SIGN                    "+"|"-"
SIGN_OPT                {SIGN}?

EXPONENT_PART           [eE]{SIGN_OPT}{DIGIT_SEQ}
EXPONENT_PART_OPT       {EXPONENT_PART}?


INTEGER_CONSTANT           {SIGN}?{NONZERO_DIGIT}{DIGIT}*|"0"

FLOAT_CONSTANT          {SIGN_OPT}{DIGIT_SEQ}"."{DIGIT_SEQ}{EXPONENT_PART_OPT}|{SIGN_OPT}{DIGIT_SEQ}{EXPONENT_PART}


C_CHAR                  [^\'\n\\']|{ESCAPE_SEQUENCE}
C_CHAR_SEQUENCE         {C_CHAR}+
CHARACTER_CONSTANT      \'{C_CHAR_SEQUENCE}\'

S_CHAR                  [^\"\n\\]|{ESCAPE_SEQUENCE}
S_CHAR_SEQUENCE         {S_CHAR}+
STRING_LITERAL          \"({S_CHAR_SEQUENCE}?)\"
WHITESPACE              [ \t\r]


%%
"char"                      {return CHAR;}
"float"                      {return FLOAT;}
"const"                      {return CONST;}
"else"                      {return ELSE;}
"for"                       {return FOR;}
"if"                        {return IF;}
"integer"                   {return INTEGER;}
"return"                    {return RETURN;}
"void"                      {return VOID;}
"while"                      {return WHILE;}
"bool"                      {return BOOL;}
"do"                        {return DO;}
"begin"                      {return CURLY_BRACE_OPEN;}
"end"                      {return CURLY_BRACE_CLOSE;}
{IDENTIFIER} {
    addToSymbolTable(yytext, "IDENTIFIER");
    return IDENTIFIER;
}

{INTEGER_CONSTANT}          {
                            addToSymbolTable(yytext, "INTEGER CONSTANT");
                            return INTEGER_CONSTANT;}
{CHARACTER_CONSTANT}        {addToSymbolTable(yytext, "CHARACTER_CONSTANT");
return CHARACTER_CONSTANT;}
{STRING_LITERAL}            {addToSymbolTable(yytext, "STRING LITERAL"); return STRING_LITERAL;}
{FLOAT_CONSTANT}          { addToSymbolTable(yytext, "FLOATING CONSTANT"); return FLOAT_CONSTANT;}

"="                         {return EQ;}
":"                         {return COLON;}
";"                         {return SEMI_COLON;}
"?"                         {return QUESTION_MARK;}
"->"                        {return PTR;}
"<"                         {return LESS_THAN;}
">"                         {return GREATER_THAN;}
"<="                        {return LTE_OP;}
">="                        {return GTE_OP;}
"=="                        {return EQ_OP;}
"&&"                        {return AND_OP;}
"||"                        {return OR_OP;}
"!="                        {return NE_OP;}
"("                         {return ROUND_BRACE_OPEN;}
")"                         {return ROUND_BRACE_CLOSE;}
"["                         {return SQ_BRACE_OPEN;}
"]"                         {return SQ_BRACE_CLOSE;}
"<<"       { return LSHIFT; }
">>"       { return RSHIFT; }
"++"       { return INC; }
"--"       { return DEC; }
"&"                         {return BITWISEAND;}
"|"                         {return BITWISEOR;}
"^"                         {return BITWISEXOR;}
"*"                         {return STAR;}
"+"                         {return PLUS;}
"-"                         {return MINUS;}
"!"                         {return EXCLAMATION;}
"/"                         {return DIVIDE;}
"%"                         {return PERCENTAGE;}
","                         {return COMMA;}

"/*"                        {BEGIN(MULTI_LINE_FLAG);}
<MULTI_LINE_FLAG>"*/"       {BEGIN(INITIAL);}
<MULTI_LINE_FLAG>.          { }
<MULTI_LINE_FLAG>"\n"       { yylineno++; printf("\n-------- Parsing Line No. %d --------\n", yylineno); }

"//"                        {BEGIN(SINGLE_LINE_FLAG);}
<SINGLE_LINE_FLAG>"\n"      {BEGIN(INITIAL); yylineno++;printf("\n-------- Parsing Line No. %d --------\n", yylineno); }
<SINGLE_LINE_FLAG>.         { }
\n                          { yylineno++; printf("\n-------- Parsing Line No. %d --------\n", yylineno); }
{WHITESPACE}                { }
.                           { printf("ERROR [Line %d] : Invalid Token %s\n",yylineno,yytext); return INVALID_TOKEN;}

%%

int yywrap() {
    print_symbol_table();  // Call function to print symbol table
    printf("\nSymbol table has been written to symbol_table.txt\n");
    return 1;
}
