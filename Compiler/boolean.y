%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

%}

%union {
    int boolean;  /* 1 for TRUE, 0 for FALSE */
}

%token <boolean> TRUE FALSE
%token AND OR NOT LPAREN RPAREN

%left OR
%left AND
%right NOT

%type <boolean> expr

%%

input:
    input expr '\n' { 
        printf("Result: %s\n", $2 ? "TRUE" : "FALSE"); 
    }
    | /* empty */
    ;

expr:
    expr AND expr { $$ = $1 && $3; }
    | expr OR expr { $$ = $1 || $3; }
    | NOT expr { $$ = !$2; }
    | LPAREN expr RPAREN { $$ = $2; }
    | TRUE { $$ = 1; }
    | FALSE { $$ = 0; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter a Boolean expression (TRUE/FALSE with AND, OR, NOT):\n");
    yyparse();
    return 0;
}
