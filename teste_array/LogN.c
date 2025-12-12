#include <stdio.h>

int lg(int N){
    int i, n;
    i = 0;
    n = 1;

    while(n <= N/2) {
        n = 2 * n;
        i += 1;
    }
    return i;
}

int main(){
    int valor = 0;

    printf("Digite valor para calcular o log: ");
    scanf("%d", &valor);

    int logvalor = lg(valor);

    printf("O log de %d eh: %d", valor, logvalor);

    return 0;
}