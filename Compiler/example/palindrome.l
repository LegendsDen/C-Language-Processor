%{
#include "y.tab.h"
#include <stdlib.h>
#include <string.h>
%}

%%

[a-zA-Z]+  { 
    yylval.str = strdup(yytext); 
    return STRING; 
}
\n      { return '\n'; }
[ \t]   { /* Ignore spaces and tabs */ }
.       { printf("Invalid character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}
