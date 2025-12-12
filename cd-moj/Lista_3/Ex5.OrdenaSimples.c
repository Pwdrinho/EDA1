#include <stdio.h>



void troca(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selecao(int *v, int n){
    for(int j = 0; j < n-1; j++){
        int min = j;
        for(int i = j+1; i < n; i++){
            if(v[i] < v[min]) min = i;
        }
        if (min != j) troca(&v[j], &v[min]);
    }
}


int main(){
    int v[1000000];
    int n = 0;

    while(scanf("%d", &v[n]) == 1){
        n++;
    }
    if(n > 0) selecao(v, n);

    for(int i =0; i < n; i++){
        if (i) putchar(' ');
        printf("%d", v[i]);
    }
    putchar('\n');

    return 0;
}

