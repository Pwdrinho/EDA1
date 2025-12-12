#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula* le, int x) {
    celula* novo = (celula*) malloc(sizeof(celula));
    novo -> dado = x;
    novo -> prox = le -> prox;
    le -> prox = novo;
}

void insere_antes(celula *le, int x, int y){
    celula *ant = le;
    celula *p = le -> prox;

    while(p != NULL && p -> dado != y){
        ant = p;
        p = p -> prox;
    }
        celula *novo = (celula*) malloc(sizeof(celula));
        novo -> dado = x;

        novo -> prox = p;
        ant -> prox = novo;
}