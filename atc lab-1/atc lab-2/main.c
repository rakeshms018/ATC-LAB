#include <stdio.h>

int main() {
    char ch, next;
    printf("Enter code with comments (ctrl+z to end):\n");
    while((ch = getchar()) != EOF) {
        if(ch == '/') {
            next = getchar();
            if(next == '/') {
                while((ch = getchar()) != '\n' && ch != EOF);
                if(ch == '\n') putchar('\n');
            } else if(next == '*') {
                while((ch = getchar()) != EOF) {
                    if(ch == '*') {
                        if((next = getchar()) == '/') break;
                    }
                }
            } else {
                putchar(ch);
                putchar(next);
            }
        } else {
            putchar(ch);
        }
    }
    return 0;
}