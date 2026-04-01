%{
#include <stdio.h>
%}

%%
"int"|"float"|"char"|"double"|"if"|"else"|"while"|"for"|"return"|"void"|"main" { printf("Keyword: %s\n", yytext); }

[0-9]+(\.[0-9]+)?          { printf("Number: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*      { printf("Identifier: %s\n", yytext); }

[+\-*/=<>!&|]               { printf("Operator: %s\n", yytext); }

[ \t\n]+                    ; /* Skip whitespace */

[(){};,]                    { printf("Separator: %s\n", yytext); }

.                           { printf("Unknown Character: %s\n", yytext); }
%%

int main() {
    printf("Enter code to identify tokens (Ctrl+Z to end on Windows):\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}