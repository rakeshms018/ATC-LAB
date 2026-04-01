#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    int lines = 0, words = 0, chars = 0, in_word = 0;
    printf("Enter text (ctrl+z to end):\n");
    while((ch = getchar()) != EOF) {
        chars++;
        if(ch == '\n') lines++;
        if(isspace(ch)) {
            in_word = 0;
        } else if(!in_word) {
            in_word = 1;
            words++;
        }
    }
    printf("\nLines: %d\nWords: %d\nCharacters: %d\n", lines, words, chars);
    return 0;
}