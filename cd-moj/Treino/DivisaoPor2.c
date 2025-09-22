#include <stdio.h>

int main() {
    // n = numero que vamos dividir
    // i = expoente de 2
    int n, i;

    scanf("%d", &n);
    scanf("%d", &i);

    int resto = n & ((1 << i) - 1);
    printf("%d \n", resto);

    return 0;
}