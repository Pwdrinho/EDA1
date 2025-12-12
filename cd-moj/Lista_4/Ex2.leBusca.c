#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

// Busca iterativa — percorre até achar o valor ou fim da lista
celula *busca(celula *le, int x) {
    celula *p = le->prox; // começa após o nó cabeça
    while (p != NULL && p->dado != x)
        p = p->prox;
    return p; // retorna NULL se não achou, ou o ponteiro para a célula que contém x
}

// Busca recursiva — mesma lógica, mas usando recursão
celula *busca_rec(celula *le, int x) {
    if (le->prox == NULL) return NULL;          // chegou ao fim → não achou
    if (le->prox->dado == x) return le->prox;   // achou o valor
    return busca_rec(le->prox, x);              // chama recursivamente no próximo
}
