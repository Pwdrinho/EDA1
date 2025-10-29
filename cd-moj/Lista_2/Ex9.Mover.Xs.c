#include <stdio.h>

void moverXs(char *s) {
    // --- Caso Base
    if (s[0] == '\0') {
        return;
    }
    // --- Passo Recursivo ---
    if (s[0] != 'x') {
        printf("%c", s[0]);
    }
    // --- Chamada Recursiva
    moverXs(s + 1);
    if (s[0] == 'x') {
        printf("%c", s[0]);
    }
}

int main() {
    char palavra[101];

    scanf("%s", palavra);
    moverXs(palavra);
    printf("\n");

    return 0;
}