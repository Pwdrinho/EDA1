#include <stdio.h>

int main() {
    int m, a, b, c, maior;

    scanf("%d", &m);
    scanf("%d", &a);
    scanf("%d", &b);

    c = m - (a + b);

    if (a > b && a > c)
        maior = a;
    else if (b > a && b > c)
        maior = b;
    else
        maior = c;
        
    printf("%d", maior);

    return 0;
}