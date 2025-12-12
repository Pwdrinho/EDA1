#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

/* Troca dois elementos */
static void troca(long long *a, long long *b) {
    long long tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Particiona (Lomuto) - retorna o índice do pivô após particionar */
static int particiona(long long v[], int low, int high) {
    long long pivot = v[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (v[j] <= pivot) {
            ++i;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i + 1], &v[high]);
    return i + 1;
}

/* Quicksort recursivo com escolha aleatória de pivô */
static void quicksort(long long v[], int low, int high) {
    if (low < high) {
        /* escolha aleatória do pivô (reduz chance de pior caso) */
        int pivot_index = low + rand() % (high - low + 1);
        troca(&v[pivot_index], &v[high]); /* coloca pivô em v[high] */
        int p = particiona(v, low, high);
        quicksort(v, low, p - 1);
        quicksort(v, p + 1, high);
    }
}

/* Busca binária clássica em vetor ordenado */
static int busca_binaria(long long v[], int n, long long chave) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (v[m] == chave) return 1;
        else if (v[m] < chave) l = m + 1;
        else r = m - 1;
    }
    return 0;
}

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    long long *proibidos = malloc(sizeof(long long) * (size_t)N);
    if (!proibidos) {
        fprintf(stderr, "Erro de alocacao\n");
        return 1;
    }

    /* Lê os N números proibidos (podem haver repetidos) */
    for (int i = 0; i < N; ++i) {
        if (scanf("%lld", &proibidos[i]) != 1) {
            /* entrada inesperada; libera e sai */
            free(proibidos);
            return 0;
        }
    }

    /* Ordena usando quicksort implementado acima */
    srand((unsigned) time(NULL));
    quicksort(proibidos, 0, N - 1);

    /* Lê consultas até EOF e responde se é proibido (sim/nao) */
    long long consulta;
    while (scanf("%lld", &consulta) == 1) {
        if (busca_binaria(proibidos, N, consulta))
            puts("sim");
        else
            puts("nao");
    }

    free(proibidos);
    return 0;
}