#include <stdio.h>
#include <string.h>

#define MAX 500

int main() {
    char expr[MAX + 5];
    char stack[MAX];
    int top = -1;

    // lê a linha inteira (com espaços se houver)
    fgets(expr, sizeof(expr), stdin);

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        // Se abre, empilha
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        }

        // Se fecha, verifica
        else if (c == ')' || c == ']' || c == '}') {
            if (top == -1) {  
                // nada para fechar → erro
                printf("nao\n");
                return 0;
            }

            char topo = stack[top--];

            if ((c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{')) {
                // par incompatível
                printf("nao\n");
                return 0;
            }
        }
    }

    // Se sobrou algo na pilha, está errado
    if (top != -1) {
        printf("nao\n");
    } else {
        printf("sim\n");
    }

    return 0;
}