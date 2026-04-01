%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *s);
int yylex();
%}

%token NUM
%left '+' '-'
%left '*' '/'
%right UMINUS

%%
S: E { printf("Result: %d\n", $1); exit(0); }
 ;
E: E '+' E { $$ = $1 + $3; }
 | E '-' E { $$ = $1 - $3; }
 | E '*' E { $$ = $1 * $3; }
 | E '/' E { 
    if($3 == 0) { yyerror("Division by zero"); exit(1); }
    $$ = $1 / $3; 
   }
 | '(' E ')' { $$ = $2; }
 | '-' E %prec UMINUS { $$ = -$2; }
 | NUM { $$ = $1; }
 ;
%%

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter arithmetic expression:\n");
    yyparse();
    return 0;
}