#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le){ 
    celula *atual = le->prox;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void imprime_rec(celula *le){
    // Caso base
    if(le->prox == NULL){
        printf("NULL\n");
        return;
    }
    // Imprime o dado do elemento atual (pulando o cabeçalho)
    if (le->dado != 0 || le->prox != NULL) {
        printf("%d -> ", le->prox->dado);
    }
    // Chamada recursiva para o próximo elemento
    imprime_rec(le->prox);
}