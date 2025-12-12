#include <stdio.h>

void insercao(int*v, int n){
    for(int j = 1; j < n; j++){
        int x = v[j];
        int i = j - 1;
        while(i >= 0 && v[i] > x){
            v[i + 1] = v[i];
            i --;
        }
        v[i + 1] = x;
    }
}
int main(){
    int v[50000];
    int n = 0;

    while(scanf("%d", &v[n]) == 1){
        n++;
    }

    insercao(v, n);

    for(int i = 0; i < n; i++){
        printf("%d", v[i]);

        if( i < n - 1){
            printf(" ");
        }
    }

    printf("\n");
    return 0;
}