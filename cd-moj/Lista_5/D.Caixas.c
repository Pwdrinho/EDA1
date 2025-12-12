#include <stdio.h>
#include <stdlib.h>

#define TAM_PILHA 10000

int main() {
    char caractere;
    int pilha[TAM_PILHA];
    int topo = -1;
    int caixas_validas = 0;
    int tem_conteudo = 0;

    while ((caractere = getchar()) != EOF) {

        if (caractere == '\n') {
            if (tem_conteudo) {
                printf("%d\n", caixas_validas);
            }

            // Reinicia para a próxima linha
            caixas_validas = 0;
            topo = -1;
            tem_conteudo = 0;
        }

        else {
            tem_conteudo = 1; 
            
            if (caractere == '[') {
                // Empurra uma nova caixa para pilha (inicialmente sem dano)
                if (topo < TAM_PILHA - 1) {
                    pilha[++topo] = 0;
                }
            }
            else if (caractere == 'x') {
                // Marca a caixa atual como danificada
                if (topo >= 0) {
                    pilha[topo] = 1;
                }
            }
            else if (caractere == ']') {
                if (topo >= 0) {
                    int estado = pilha[topo--]; // remove caixa atual
                    
                    // Se a caixa não tem dano, é válida
                    if (estado == 0) {
                        caixas_validas++;
                    } 
                    // Se tem dano, a caixa externa também passa a ser danificada
                    else {
                        if (topo >= 0) {
                            pilha[topo] = 1;
                        }
                    }
                }
            }
        }
    }

    // Caso a última linha não termine em '\n'
    if (tem_conteudo) {
        printf("%d\n", caixas_validas);
    }

    return 0;
}
