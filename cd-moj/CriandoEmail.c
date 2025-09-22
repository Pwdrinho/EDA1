#include <stdio.h>

char to_lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32; // tabela ASCII
    }
    return c;
}

int main() {
    char nome[101];
    char primeiro[101], ultimo[101];
    int i = 0, j = 0, k = 0;

    fgets(nome, 101, stdin);

    for (i = 0; nome[i] != '\0'; i++) {
        if (nome[i] == '\n') {
            nome[i] = '\0';
            break;
        }
    }

    i = 0; j = 0;
    while (nome[i] != ' ' && nome[i] != '\0') {
        primeiro[j++] = to_lower(nome[i]);
        i++;
    }
    primeiro[j] = '\0';

    int fim = 0;
    while (nome[fim] != '\0') fim++;

    int inicio_ultimo = fim - 1;
    while (inicio_ultimo > 0 && nome[inicio_ultimo - 1] != ' ') {
        inicio_ultimo--;
    }

    k = 0;
    while (nome[inicio_ultimo] != '\0') {
        ultimo[k++] = to_lower(nome[inicio_ultimo]);
        inicio_ultimo++;
    }
    ultimo[k] = '\0';

    printf("%s.%s@unb.br\n", primeiro, ultimo);

    return 0;
}