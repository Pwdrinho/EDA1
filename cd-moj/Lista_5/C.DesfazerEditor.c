#include <stdio.h>
#include <string.h>

#define MAX_STR 101
#define MAX_STACK 100000

typedef struct {
    char itens[MAX_STACK][MAX_STR];
    int topo;
} Pilha;

// Inicializa a pilha
void criarPilha(Pilha *p) {
    p->topo = -1;
}

// Verifica se está vazia
int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

// Empilha string
void empilhar(Pilha *p, char str[]) {
    strcpy(p->itens[++p->topo], str);
}

// Desempilha string
// Retorna 1 se deu certo, 0 se vazia
int desempilhar(Pilha *p, char str[]) {
    if (pilhaVazia(p)) return 0;

    strcpy(str, p->itens[p->topo--]);
    return 1;
}

int main() {
    Pilha p;
    criarPilha(&p);

    char comando[10];
    char texto[MAX_STR];
    char resultado[MAX_STR];

    while (scanf("%s", comando) != EOF) {

        if (strcmp(comando, "inserir") == 0) {
            getchar();                
            fgets(texto, MAX_STR, stdin);
            texto[strcspn(texto, "\n")] = '\0';

            empilhar(&p, texto);
        }

        else if (strcmp(comando, "desfazer") == 0) {
            if (desempilhar(&p, resultado)) {
                printf("%s\n", resultado);
            } else {
                printf("NULL\n");
            }
        }
    }

    return 0;
}