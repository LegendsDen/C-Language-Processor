#include <stdio.h>
extern int yyparse();
extern void print_symbol_table();

int main() {
    printf("-------------------- Parsing --------------------\n\n");
    yyparse();
    print_symbol_table();

    return 0;
}