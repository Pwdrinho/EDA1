#include <stdio.h>

int main() {
    int n;
    int soma = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        soma += x ;
    }
    printf("%d \n", soma);

    return 0;
}