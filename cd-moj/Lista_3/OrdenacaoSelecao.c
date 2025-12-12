#include <stdio.h>

#define MAX 1000

void troca(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selecao(int *v, int n){
    for(int j = 0; j < n - 1; j++){
        int min = j;
        for(int i = j + 1; i < n; i++){
            if (v[i] < v[min]) min = i;
        }
        if (min != j) troca(&v[j], &v[min]);
    }
}

int main(void){
    int v[MAX];
    int n = 0;
    int x;

    while (scanf("%d", &x) == 1) {
        if (n < MAX) {
            v[n++] = x;
        } else {
            /* protecao: ignorar extras (ou podemos sair com erro) */
            break;
        }
    }


    if (n > 0) selecao(v, n);

    for (int i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", v[i]);
    }
    putchar('\n');
    return 0;
}