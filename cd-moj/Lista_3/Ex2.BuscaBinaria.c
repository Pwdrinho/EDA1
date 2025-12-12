#include <stdio.h>
#include <stdlib.h>

long long int busca_binaria(int *v, long long int e, long long int d, int x){
    if(e < d - 1){
        long long int m = (e + d)/2;
        if(v[m] >= x) {
            return busca_binaria(v,e,m,x);
        }
        else return busca_binaria(v, m, d, x);
    }
    return d;
}

int main(){

    long long int N, M;
    scanf("%lld %lld", &N, &M);

    int *v = malloc(N * sizeof(int));

    for(long long int i = 0; i < N; i++){
        scanf("%d", &v[i]);
    }

    int x;
    for(long long int i = 0; i < M; i++){
        scanf("%d", &x);
        printf("%lld\n", busca_binaria(v, -1, N, x));
    }

    free(v);
    return 0;
}