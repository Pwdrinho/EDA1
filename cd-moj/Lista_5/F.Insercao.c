#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *enfileira(celula *f, int x) {
    // 1. Aloca o novo nó
    celula *novo = (celula *) malloc(sizeof(celula));
    if (novo == NULL) return NULL;
    
    novo->dado = x;

    // 2. Caso Fila Vazia
    if (f == NULL) {
        novo->prox = novo;
        return novo;
    }

    // 3. Caso Fila com Elementos
    celula *aux = f;
    while (aux->prox != f) {
        aux = aux->prox;
    }

    // 4. Inserção
    aux->prox = novo; 
    novo->prox = f;  

    return f;
}