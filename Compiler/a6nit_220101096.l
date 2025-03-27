%{
#define KEYWORD 10
#define IDENTIFIER 11
#define INT_CONSTANT 12
#define FLOAT_CONSTANT 13
#define CHAR_CONSTANT 14
#define STRING_LITERAL 15
#define PUNCTUATOR 16
#define SINGLE_LINE_COMMENT 17
#define MULTI_LINE_COMMENT 18
#define INVALID_TOKEN -1

int line_number = 1;

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

%x MULTI_LINE_COMM
%x SINGLE_LINE_COMM

WHITESPACE              [ \t\r\f\v]+
NEWLINE                 \n|\r\n

/* Keywords from micro C specification */
KEYWORD                 "return"|"void"|"float"|"integer"|"char"|"for"|"const"|"while"|"bool"|"if"|"do"|"else"|"begin"|"end"

/* Identifier rules */
IDENTIFIER_NONDIGIT     [a-zA-Z_]
DIGIT                   [0-9]
IDENTIFIER              {IDENTIFIER_NONDIGIT}({IDENTIFIER_NONDIGIT}|{DIGIT})*

/* Integer Constant rules */
NONZERO_DIGIT           [1-9]
Zero                    "0"
INTEGER_CONSTANT        ({Zero}+{NONZERO_DIGIT}{DIGIT}*)|({Zero}+)|({NONZERO_DIGIT}{DIGIT}*)

/* Floating Constant rules */
DIGIT_SEQUENCE          {DIGIT}+
EXPONENT_PART           [eE][+-]?{DIGIT_SEQUENCE}
FRACTIONAL_CONSTANT     ({DIGIT_SEQUENCE}?"."{DIGIT_SEQUENCE})|({DIGIT_SEQUENCE}".")
FLOATING_CONSTANT       ({FRACTIONAL_CONSTANT}{EXPONENT_PART}?)|({DIGIT_SEQUENCE}{EXPONENT_PART})

/* Character Constant rules */
ESCAPE_SEQ              "\\'"|"\\\""|"\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"
C_CHAR                  [^\'\n\\]|{ESCAPE_SEQ}
C_CHAR_SEQ              {C_CHAR}+
CHAR_CONSTANT           "'"{C_CHAR_SEQ}"'"

/* String Literal rules */
S_CHAR                  [^\"\n\\]|{ESCAPE_SEQ}
S_CHAR_SEQ              {S_CHAR}+
STRING_LITERAL          "\""{S_CHAR_SEQ}?"\""

/* Punctuators from micro C */
PUNCTUATOR              "{"|"}"|"^"|">>"|"<<"|"++"|"--"|"=="|"!="|"<="|">="|"="|"+"|"-"|"*"|"/"|"%"|"!"|"?"|"<"|">"|"&&"|"||"|":"|";"|","|"("|")"|"["|"]"|"->"|"&"|"\|"

%%

{KEYWORD}               { fprintf(token_file, "<KEYWORD, %s, line %d>\n", yytext, line_number);
                          addToSymbolTable(yytext, "KEYWORD"); }
                          
{IDENTIFIER}            { fprintf(token_file, "<IDENTIFIER, %s, line %d>\n", yytext, line_number);
                          addToSymbolTable(yytext, "IDENTIFIER"); }
                          
{INTEGER_CONSTANT}      { fprintf(token_file, "<INTEGER_CONSTANT, %s, line %d>\n", yytext, line_number);
                          addToSymbolTable(yytext, "INTEGER CONSTANT"); }
                          
{FLOATING_CONSTANT}     { fprintf(token_file, "<FLOATING_CONSTANT, %s, line %d>\n", yytext, line_number);
                          addToSymbolTable(yytext, "FLOATING CONSTANT"); }
                          
{CHAR_CONSTANT}         { fprintf(token_file, "<CHAR_CONSTANT, %s, line %d>\n", yytext, line_number);
                          addToSymbolTable(yytext, "CHAR CONSTANT"); }
                          
{STRING_LITERAL}        { fprintf(token_file, "<STRING_LITERAL, %s, line %d>\n", yytext, line_number);
                          addToSymbolTable(yytext, "STRING LITERAL"); }
                          
{PUNCTUATOR}            { fprintf(token_file, "<PUNCTUATOR, %s, line %d>\n", yytext, line_number); }

"/*"                    { BEGIN(MULTI_LINE_COMM); }
<MULTI_LINE_COMM>"*/"   { BEGIN(INITIAL); 
                          fprintf(token_file, "<MULTI_LINE_COMMENT, line %d>\n", line_number); }
<MULTI_LINE_COMM>{NEWLINE} { line_number++; }
<MULTI_LINE_COMM>.      { /* Ignore content */ }

"//"                    { BEGIN(SINGLE_LINE_COMM); }
<SINGLE_LINE_COMM>{NEWLINE} { BEGIN(INITIAL); 
                              fprintf(token_file, "<SINGLE_LINE_COMMENT, line %d>\n", line_number-1);
                              line_number++; }
<SINGLE_LINE_COMM>.     { /* Ignore content */ }

{WHITESPACE}            { /* Ignore whitespace */ }
{NEWLINE}               { line_number++; }

.                       { fprintf(token_file, "<INVALID_TOKEN, %s, line %d>\n", yytext, line_number); }

%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename.mc>\n", argv[0]);
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

    yylex();  // Single call to yylex(), non-iterative

    printf("Lexical Analysis Completed. Check tokens.txt and symbol_table.txt\n");

    fprintf(symbol_file, "SYMBOL TABLE\n----------------\n");
    for (int i = 0; i < symbolCount; i++) {
        fprintf(symbol_file, "%-20s : %s\n", symbolTable[i].name, symbolTable[i].type);
    }

    fclose(input_file);
    fclose(token_file);
    fclose(symbol_file);
    return 0;
}