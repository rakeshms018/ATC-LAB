%{
#include "calc.tab.h"
#include <stdlib.h>
%}

%%
[0-9]+  { yylval = atoi(yytext); return NUM; }
[ \t]   ; /* skip whitespace */
\n      { return 0; }
.       { return yytext[0]; }
%%

int yywrap() {
    return 1;
}