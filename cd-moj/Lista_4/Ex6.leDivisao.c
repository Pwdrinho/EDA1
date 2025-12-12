#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void divide_lista(celula *l, celula *l1, celula *l2) {
    celula *p = l->prox;   
    celula *fim1 = l1;     
    celula *fim2 = l2;     

    while (p != NULL) {
        celula *prox = p->prox; 
        if (p->dado % 2 == 0) { // par
            fim2->prox = p;
            fim2 = p;
        } else {                // ímpar
            fim1->prox = p;
            fim1 = p;
        }
        p->prox = NULL; 
        p = prox;       
    }

    fim1->prox = NULL;
    fim2->prox = NULL;
}
