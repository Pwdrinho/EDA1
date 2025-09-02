#include <stdio.h>
#include <string.h>

int fatorial (int n) {
    int resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    char data[20];
    int repeticao[10] = {0};
    int numerador, denominador = 1, resultado;

    scanf("%s", data);

    int tamanho = strlen(data);
    for (int i = 0; i < tamanho; i++) {
        if (data[i] >= '0' && data[i] <= '9') {
            int digito = data[i] - '0';
            repeticao[digito]++;
        }
    }

    numerador = fatorial(6);

    for (int i = 0; i < 10; i++) {
        if (repeticao[i] > 1) {
            denominador *= fatorial(repeticao[i]);
        }
    }

    resultado = numerador / denominador;
    printf("%d \n", resultado);

    return 0;
}