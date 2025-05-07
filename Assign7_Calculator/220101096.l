%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "220101096.tab.h"

void yyerror(const char *s);
%}

%option noyywrap

%%

"expr"         { return EXPRESSION; }
"bintodec"     { return BINTODEC; }
"bintohex"     { return BINTOHEX; }
"hextobin"     { return HEXTOBIN; }
"hextodec"     { return HEXTODEC; }

[0-9A-Fa-f]+   { yylval.sval = strdup(yytext); return NUMBER; }

"+"            { return '+'; }
"-"            { return '-'; }
"*"            { return '*'; }
"/"            { return '/'; }
"**"           { return POWER; }
"("            { return '('; }
")"            { return ')'; }

[ \t\n]        ; /* Ignore whitespace */

.              { yyerror("Invalid character"); }

%%