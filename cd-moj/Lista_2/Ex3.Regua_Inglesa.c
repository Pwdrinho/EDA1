#include <stdio.h>

void imprimir_tracos(int n) {
    printf(".");
    for (int i = 0; i < n; i++) {
        printf("-");
    }
    printf("\n");
}

void desenhar_regua(int n) {
    if (n > 0) {
        // 1. Desenha a régua superior de ordem n-1.
        desenhar_regua(n - 1);
        
        // 2. Imprime a marca central com 'n' traços.
        imprimir_tracos(n);
        
        // 3. Desenha a régua inferior de ordem n-1.
        desenhar_regua(n - 1);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        desenhar_regua(n);
    }
    return 0;
}