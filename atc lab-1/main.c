#include <stdio.h>
#include <ctype.h>
#include <string.h>

void identify(char *token) {
    char *keywords[] = {"int", "float", "char", "double", "if", "else", "while", "for", "return", "void", "main"};
    for(int i = 0; i < 11; i++) {
        if(strcmp(token, keywords[i]) == 0) {
            printf("Keyword: %s\n", token);
            return;
        }
    }
    if(isdigit(token[0])) printf("Number: %s\n", token);
    else printf("Identifier: %s\n", token);
}

int main() {
    int ch;
    char buf[256];
    int i = 0;
    printf("Enter code (ctrl+z to end):\n");
    while((ch = getchar()) != EOF) {
        if(isalnum(ch) || ch == '_') {
            if(i < (int)sizeof(buf) - 1) {
                buf[i++] = (char)ch;
            } else {
                // token too long; terminate and reset to avoid overflow
                buf[i] = '\0';
                identify(buf);
                i = 0;
                buf[i++] = (char)ch;
            }
        } else {
            if(i != 0) {
                buf[i] = '\0';
                identify(buf);
                i = 0;
            }
            if(strchr("+-*/=<>!&|", ch)) {
                printf("Operator: %c\n", ch);
            } else if(strchr("(){};,", ch)) {
                printf("Separator: %c\n", ch);
            }
        }
    }
    if(i != 0) {
        buf[i] = '\0';
        identify(buf);
    }
    return 0;
}