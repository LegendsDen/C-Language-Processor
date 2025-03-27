%{
#include "y.tab.h"
%}

%%

[0-9]+  { yylval.num = atoi(yytext); return NUMBER; }
"("     { return LPAREN; }
")"     { return RPAREN; }
"+"     { return PLUS; }
"-"     { return MINUS; }
"*"     { return TIMES; }
"/"     { return DIVIDE; }
[ \t]   { /* Ignore spaces and tabs */ }
\n      { return '\n'; }
.       { printf("Invalid character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}
