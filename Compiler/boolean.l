%{
#include "y.tab.h"
%}

%%

"TRUE"  { yylval.boolean = 1; return TRUE; }
"FALSE" { yylval.boolean = 0; return FALSE; }
"AND"   { return AND; }
"OR"    { return OR; }
"NOT"   { return NOT; }
"("     { return LPAREN; }
")"     { return RPAREN; }
[ \t]   { /* Ignore spaces */ }
\n      { return '\n'; }
.       { printf("Invalid character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}
