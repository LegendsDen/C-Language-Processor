%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

%}

%union {
    char *str;
}

%token <str> STRING

%%

input:
    input STRING '\n' {
        int len = strlen($2);
        int is_palindrome = 1;
        
        for (int i = 0; i < len / 2; i++) {
            if ($2[i] != $2[len - i - 1]) {
                is_palindrome = 0;
                break;
            }
        }
        
        if (is_palindrome) {
            printf("Palindrome\n");
        } else {
            printf("Not a Palindrome\n");
        }
        
        free($2);
    }
    | /* empty */
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter a string to check if it's a palindrome:\n");
    yyparse();
    return 0;
}
