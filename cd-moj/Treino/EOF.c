#include <stdio.h>

int main() {
    int contador = 0;
    int numero;

    while (scanf("%d", &numero) != EOF) {
        contador++;
    };
    printf("%d \n", contador);

    return 0;
}