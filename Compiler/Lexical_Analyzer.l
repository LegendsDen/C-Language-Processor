%{
#define KEYWORD 10
#define IDENTIFIER 11
#define INT_CONSTANT 12
#define CHAR_CONSTANT 13
#define STRING_LITERAL 14
#define PUNCTUATOR 15
#define SINGLE_LINE_COMMENT 16
#define MULTI_LINE_COMMENT 17
#define INVALID_TOKEN -1

int line_number=1;

FILE *token_file, *symbol_file;

typedef struct {
    char name[100];
    char type[20];
} Symbol;

Symbol symbolTable[1000];
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


%}

/* Explicit state definitions for multi-line and single-line comments */
%x MULTI_LINE_COMM
%x SINGLE_LINE_COMM

/* Improved whitespace definitions */
WHITESPACE              [ \t\r\f\v]+
NEWLINE                 \n|\r\n

KEYWORD                 "char"|"else"|"for"|"if"|"int"|"return"|"void"
IDENTIFIER              [a-zA-Z_][a-zA-Z0-9_]*

DIGIT                   [0-9]
DIGIT_SEQ               [0-9]+
NONZERO_DIGIT          [1-9]
SIGN                    "+"|"-"
INT_CONSTANT           {SIGN}?{NONZERO_DIGIT}{DIGIT}*|"0"

ESCAPE_SEQ             "\\\'"|"\\\""|"\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"
C_CHAR                 [^\'\n\\]|{ESCAPE_SEQ}
C_CHAR_SEQ            {C_CHAR}+
CHAR_CONSTANT         \'{C_CHAR_SEQ}\'

S_CHAR                [^\"\n\\]|{ESCAPE_SEQ}
S_CHAR_SEQ           {S_CHAR}+
STRING_LITERAL       \"([^\"\n\\]|\\.)*\"

PUNCTUATOR           "=="|"!="|"<="|">="|"="|"+"|"-"|"*"|"/"|"%"|"!"|"?"|"<"|">"|"&&"|"||"|":"|";"|","|"("|")"|"{"|"}"|"["|"]"|"->"|"&"

%%

{KEYWORD}               { fprintf(token_file, "<KEYWORD, %s>\n", yytext);
                            addToSymbolTable(yytext, "KEYWORD");
                            return KEYWORD; 
                        }
{IDENTIFIER}            { fprintf(token_file, "<IDENTIFIER, %s>\n", yytext);
                            addToSymbolTable(yytext, "IDENTIFIER");
                            return IDENTIFIER; }
{INT_CONSTANT}          {fprintf(token_file, "<INT_CONSTANT, %s>\n", yytext);
                            addToSymbolTable(yytext, "INTEGER CONSTANT");
                            return INT_CONSTANT;
                            }
{CHAR_CONSTANT}         { fprintf(token_file, "<CHAR_CONSTANT, %s>\n", yytext);
                            addToSymbolTable(yytext, "CHAR CONSTANT");
                            return CHAR_CONSTANT;  }
{STRING_LITERAL}        { fprintf(token_file, "<STRING_LITERAL, %s>\n", yytext);
                            addToSymbolTable(yytext, "STRING LITERAL");
                            return STRING_LITERAL; }
{PUNCTUATOR}            {fprintf(token_file, "<PUNCTUATOR, %s>\n", yytext);
                            return PUNCTUATOR; }

"/*"                    { BEGIN(MULTI_LINE_COMM); }
<MULTI_LINE_COMM>"*/"   { BEGIN(INITIAL); return MULTI_LINE_COMMENT; }
<MULTI_LINE_COMM>{NEWLINE}    { line_number++; }
<MULTI_LINE_COMM>.      { /* Ignore everything else in multi-line comments */ }

"//"                    { BEGIN(SINGLE_LINE_COMM); }
<SINGLE_LINE_COMM>{NEWLINE}  { BEGIN(INITIAL); line_number++; return SINGLE_LINE_COMMENT; }
<SINGLE_LINE_COMM>.     {  }

{WHITESPACE}            {  }
{NEWLINE}               { line_number++; /* Track line numbers */ }

.                       {  fprintf(token_file, "UNEXPECTED TOKEN '%s' at line %d\n", yytext, yylineno);
                            return INVALID_TOKEN;
                             }

%%

int yywrap() {
    return 1;
}



int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename.nc>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }
    yyin = input_file;

    token_file = fopen("tokens.txt", "w");
    symbol_file = fopen("symbol_table.txt", "w");

    while (yylex()) { }


    printf("Lexical Analysis Completed. Check tokens.txt and symbol_table.txt\n");

    fprintf(symbol_file, "SYMBOL TABLE\n----------------\n");
    for (int i = 0; i < symbolCount; i++) {
        fprintf(symbol_file, "%s : %s\n", symbolTable[i].name, symbolTable[i].type);
    }

    fclose(input_file);
    fclose(token_file);
    fclose(symbol_file);
    return 0;
} 