#include <stdio.h>
#include <string.h>

void moveXs(char *s) {
    if (s[0] == '\0') {
        return;
    }
    if (s[0] != 'x') {
        printf("%c", s[0]);
    }

    moveXs(s + 1);

    if (s[0] == 'x') {
        printf("%c", s[0]);
    }
}

int main() {
    char str[102];
    if (fgets(str, sizeof(str), stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
        moveXs(str);
        printf("\n");
    }

    return 0;
}