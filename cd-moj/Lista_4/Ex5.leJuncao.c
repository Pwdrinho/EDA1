#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3) {
    celula *p1 = l1->prox;
    celula *p2 = l2->prox;
    celula *p3 = l3; // começa no nó cabeça de l3

    // Enquanto houver elementos em ambas as listas
    while (p1 != NULL && p2 != NULL) {
        if (p1->dado <= p2->dado) {
            p3->prox = p1;     // liga o menor nó
            p1 = p1->prox;     // avança em l1
        } else {
            p3->prox = p2;     // liga o menor nó
            p2 = p2->prox;     // avança em l2
        }
        p3 = p3->prox;         // avança em l3
    }

    // Liga o restante da lista não vazia (se houver)
    if (p1 != NULL) p3->prox = p1;
    else p3->prox = p2;
}