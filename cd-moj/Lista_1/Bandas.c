#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[80];
    int ano;
} tipoBanda;

typedef struct {
    char nome[80];
    int qtd;
    tipoBanda bandas[100];
} tipoShow;

void pesquisarNomeBanda(char pesquisa[80], tipoShow shows[50], int n) {
    int achou = 0;
    for (int s = 0; s < n; s++) {
        for (int b = 0; b < shows[s].qtd; b++) {
            int iguais = 1;
            for (int k = 0; k < 80; k++) {
                if (pesquisa[k] != shows[s].bandas[b].nome[k]) {
                    iguais = 0;
                    break;
                }
                if (pesquisa[k] == '\0') break;
            }
            if (iguais) {
                printf("%s : ano %d\n", shows[s].nome, shows[s].bandas[b].ano);
                achou = 1;
            }
        }
    }
    if (!achou) {
        printf("Banda nao cadastrada\n");
    }
}