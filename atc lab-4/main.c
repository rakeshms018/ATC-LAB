#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_email(char *s) {
    char *at = strchr(s, '@');
    char *dot = strrchr(s, '.');
    return (at && dot && at < dot);
}

int is_phone(char *s) {
    if(s[0] == '+') s++;
    for(int i=0; s[i] != '\0'; i++) if(!isdigit(s[i])) return 0;
    return (strlen(s) >= 10);
}

int main() {
    char buf[100];
    printf("Enter strings to validate (ctrl+z to end):\n");
    while(scanf("%s", buf) != EOF) {
        if(is_email(buf)) printf("Valid Email: %s\n", buf);
        else if(is_phone(buf)) printf("Valid Phone: %s\n", buf);
        else printf("Invalid Pattern: %s\n", buf);
    }
    return 0;
}