#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
//piramide 1
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            printf("%.2d ", i+1);
        }
    printf("\n");
    }
    printf("\n");
//piramide 2
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            printf("%.2d ", j+1);
        }
    printf("\n");
    }
    return 0;
}