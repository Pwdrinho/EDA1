#include <stdio.h>
#include <stdlib.h>

void intercala(int *v, int e, int m, int d){
    int i = e, j = m + 1, k = 0;
    int *w = malloc((d - e + 1) * sizeof(int));
    while (i <= m && j <= d){
        if(v[i] < v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }
    while (i <= m) w[k++] = v[i++];
    while (j <= d) w[k++] = v[j++];
    for(i = e, k = 0; i <= d; i++,k++) v[i] = w[k];
    free(w);
}

void mergesort(int *v, int e, int d){
    if(e < d){
        int m = (e + d)/2;
        mergesort(v, e, m);
        mergesort(v, m + 1, d);
        intercala(v, e, m, d);
    }
}

int main(){

    int n = 0; 
    int *v = NULL;
    int tamanho = 0;

    for(int j = 0; j < 8; j++){ 
        scanf("%d", &n);
        
        int *temp = realloc(v, (n + tamanho) * sizeof(int));
        v = temp;

        for(int i = tamanho; i < n + tamanho; i++){
            scanf("%d", &v[i]);
        }
    
        tamanho += n;
    }
    
    mergesort(v, 0, tamanho - 1);
    
    for(int i = 0; i < tamanho; i++){
        if(i+1 == tamanho) printf("%d", v[i]);
        else printf("%d ", v[i]);
    }

    free(v);
    return 0;
}