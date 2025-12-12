#include <stdio.h>

// ----------- Função de troca -----------
void troca(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// ----------- Função particiona -----------
int particiona(int v[], int e, int d) {
    int pivo = v[d];  // pivô escolhido como último elemento
    int i = e - 1;

    for (int j = e; j < d; j++) {
        if (v[j] <= pivo) {
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i + 1], &v[d]);
    return i + 1;
}

// ----------- Quicksort Recursivo -----------
void quicksort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particiona(v, inicio, fim);
        quicksort(v, inicio, p - 1);
        quicksort(v, p + 1, fim);
    }
}

// ----------- Busca Binária -----------
int buscaBinaria(int v[], int n, int chave) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (v[meio] == chave)
            return meio;
        else if (v[meio] < chave)
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

// ----------- Programa Principal -----------
int main() {
    int N, C;
    scanf("%d %d", &N, &C);

    int original[N], ordenada[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &original[i]);
        ordenada[i] = original[i];
    }

    // Ordenar usando quicksort com particiona()
    quicksort(ordenada, 0, N - 1);

    // Buscar índice da Senha Chave
    int idx = buscaBinaria(ordenada, N, C);
    int indiceSecreto = idx;  // convertendo para 1-based
    printf("%d\n", indiceSecreto);

    // Criar nova lista
    for (int i = indiceSecreto; i < N; i++)
        printf("%d ", original[i]);
    for (int i = 0; i < indiceSecreto; i++)
        printf("%d%c", original[i], (i == indiceSecreto - 1 ? '\n' : ' '));

    return 0;
}