%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(const char *s);

// Conversion functions
int bintodec(const char* binary);
char* bintohex(const char* binary);
char* hextobin(const char* hex);
int hextodec(const char* hex);
int numtodec(const char* number);
%}

%union {
    int ival;
    char* sval;
    double dval;    
}

%token <sval> NUMBER
%token EXPRESSION BINTODEC BINTOHEX HEXTOBIN HEXTODEC
%token '+' '-' '*' '/' POWER '(' ')'

%type <dval> expression term factor 

%left '+' '-'
%left '*' '/'
%right POWER

%%

program:
    | program statement
;

statement:
    EXPRESSION '(' expression ')'   { printf("Result: %g\n", $3); }
    | BINTODEC '(' NUMBER ')' { 
        int result = bintodec($3);
        printf("Result: %d\n", result);
        free($3);
    }
    | BINTOHEX '(' NUMBER ')' {
        char* result = bintohex($3);
        printf("Result: %s\n", result);
        free($3);
        free(result);
    }
    | HEXTOBIN '(' NUMBER ')' {
        char* result = hextobin($3);
        printf("Result: %s\n", result);
        free($3);
        free(result);
    }
    | HEXTODEC '(' NUMBER ')' {
        int result = hextodec($3);
        printf("Result: %d\n", result);
        free($3);
    }
;

expression:
    expression '+' term    { $$ = $1 + $3; }
    | expression '-' term { $$ = $1 - $3; }
    | term                  { $$ = $1; }
;

term:
    term '*' factor { $$ = $1 * $3; }
    | term '/' factor { 
        if ($3 == 0) {
            yyerror("Division by zero");
            $$ = 0;
        } else {
            $$ = $1 / $3; 
        }
    }
    | factor             { $$ = $1; }
;

factor:
    NUMBER               { $$ = atoi($1) ; }
    | '(' expression ')' { $$ = $2; }
    | factor POWER factor { $$ = pow($1, $3); }
;

%%

int numtodec(const char* number){
    return atoi(number) ; 
}

int bintodec(const char* binary) {
    int decimal = 0;
    int power = 0;
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        else if(binary[i]!='0'){
            yyerror("Invalid binary digit");
            return NULL;
        }
        power++;
    } 
    return decimal;
}



char* bintohex(const char *binary){

    int decimal=bintodec(binary);
    char *hex=malloc(10*sizeof(char));
    sprintf(hex,"%X",decimal);
    return hex;
}
// Hexadecimal to Binary conversion
char* hextobin(const char* hex) {
    char* binary = (char*)malloc((strlen(hex) * 4 + 1) * sizeof(char));
    binary[0] = '\0';
    
    for (int i = 0; hex[i]; i++) {
        int decimal;
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal = hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal = hex[i] - 'a' + 10;
        } else {
            yyerror("Invalid hexadecimal digit");
            free(binary);
            return NULL;
        }
        
        // Convert decimal to 4-bit binary
        char temp[5];
        for (int j = 3; j >= 0; j--) {
            temp[3-j] = (decimal & (1 << j)) ? '1' : '0';
        }
        temp[4] = '\0';
        
        strcat(binary, temp);
    }
    
    return binary;
}


int hextodec(const char *hex){
    return (int)strtol(hex,NULL,16);
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Calculator Program\n");
    printf("Enter expressions like: expr(5+4*5/2-4**2)\n");
    printf("Conversion examples:\n");
    printf("  bintodec(0001101010)\n");
    printf("  bintohex(010101000)\n");
    printf("  hextobin(2F)\n");
    printf("  hextodec(1A3)\n");
   
    yyparse();
    return 0;
}