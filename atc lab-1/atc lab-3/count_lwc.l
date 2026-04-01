%{
#include <stdio.h>
int lines = 0, words = 0, chars = 0;
%}

%%
\n      { lines++; chars++; }
[^\t\n ]+ { words++; chars += strlen(yytext); }
.       { chars++; }
%%

int main() {
    printf("Enter text to count lines, words, and characters (Ctrl+Z to end):\n");
    yylex();
    printf("\nLines: %d\nWords: %d\nCharacters: %d\n", lines, words, chars);
    return 0;
}

int yywrap() {
    return 1;
}