#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *pos;

int parse_expr();
int parse_term();
int parse_factor();

int parse_expr() {
    int res = parse_term();
    while(*pos == '+' || *pos == '-') {
        char op = *pos++;
        if(op == '+') res += parse_term();
        else res -= parse_term();
    }
    return res;
}

int parse_term() {
    int res = parse_factor();
    while(*pos == '*' || *pos == '/') {
        char op = *pos++;
        if(op == '*') res *= parse_factor();
        else res /= parse_factor();
    }
    return res;
}

int parse_factor() {
    if(isdigit(*pos)) {
        int res = 0;
        while(isdigit(*pos)) res = res * 10 + (*pos++ - '0');
        return res;
    } else if(*pos == '(') {
        pos++;
        int res = parse_expr();
        pos++; // Skip ')'
        return res;
    }
    return 0;
}

int main() {
    char input[100];
    printf("Enter arithmetic expression: ");
    scanf("%s", input);
    pos = input;
    printf("Result: %d\n", parse_expr());
    return 0;
}