%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);
%}

%union {
    char str[100];
}

%token <str> NUMBER
%token PLUS MINUS TIMES DIVIDE LPAREN RPAREN

%left PLUS MINUS
%left TIMES DIVIDE
%right UMINUS  /* Unary minus has higher precedence */

%type <str> expr

%%

input:
    input expr '\n' { printf("Postfix: %s\n", $2); }
    | /* empty */
    ;

expr:
    expr PLUS expr    { sprintf($$, "%s %s +", $1, $3); }
    | expr MINUS expr { sprintf($$, "%s %s -", $1, $3); }
    | expr TIMES expr { sprintf($$, "%s %s *", $1, $3); }
    | expr DIVIDE expr { sprintf($$, "%s %s /", $1, $3); }
    | LPAREN expr RPAREN { strcpy($$, $2); }
    | MINUS expr %prec UMINUS { sprintf($$, "%s ~", $2); } // Unary minus
    | NUMBER { strcpy($$, $1); }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter an infix expression:\n");
    yyparse();
    return 0;
}
