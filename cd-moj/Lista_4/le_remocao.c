#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void remove_inicio(celula*le){
    celula *lixo = le -> prox;
    le -> prox = lixo -> prox;
    int dado = lixo -> prox;
    free(lixo);
    return dado;
}

void remove_depois(celula *p){
    if (p == NULL || p->prox == NULL) return;
    celula *lixo = p->prox;
    p->prox = lixo->prox;
    free(lixo);
}

void remove_elemento(celula *le, int x){
    while(le -> prox != NULL && le -> prox -> dado != x){
        le = le -> prox;
    }
    if(le -> prox != NULL){
        remove_inicio(le);
    }
}
void remove_todos_elementos(celula*le, int x){
    if (le == NULL) return;
    celula *p = le;
    while (p->prox != NULL) {
        if (p->prox->dado == x) {
            remove_depois(p);
        } else {
            p = p->prox;
        }
    }
}