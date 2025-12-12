#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int desenfileira(fila *f, int *y) {
    // Fila vazia
    if (f->p == f->u)
        return 0;

    // Pega elemento da frente
    *y = f->dados[f->p];

    // Avança p circularmente
    f->p = (f->p + 1) % f->N;

    return 1;
}