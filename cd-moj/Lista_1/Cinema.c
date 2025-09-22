#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_Fileiras 20   // Máximo de fileiras (A até T)
#define MAX_Lugares 25   // Máximo de lugares por fileira

int main() {
    int Fileiras, Lugares; // Quantidade de fileiras e lugares por fileira
    char sala[MAX_Fileiras][MAX_Lugares][3]; // Matriz da sala: [fileira][lugar][string de 2 caracteres + '\0']
    // 1. Leitura da primeira linha: F (fileiras) e L (lugares por fileira)
    scanf("%d %d", &Fileiras, &Lugares);
    // 2. Inicializa todos os lugares como "--" (vazio)
    for (int i = 0; i < Fileiras; i++) {
        for (int j = 0; j < Lugares; j++) {
            strcpy(sala[i][j], "--");
        }
    }
    // 3. Leitura dos bilhetes até EOF
    char bilhete[5]; // Exemplo de bilhete: A2, B15, etc.
    while (scanf("%s", bilhete) != EOF) {
        char letra = bilhete[0];          // Primeira letra é a fileira
        int numero = atoi(&bilhete[1]);   // O restante é o número do lugar

        int linha = letra - 'A';          // Transforma letra da fileira em índice (A=0, B=1, etc.)
        int coluna = numero - 1;          // Ajusta o número do lugar para índice (1 vira 0)

        // Verifica se está dentro dos limites
        if (linha >= 0 && linha < Fileiras && coluna >= 0 && coluna < Lugares) {
            strcpy(sala[linha][coluna], "XX"); // Marca como ocupado
        }
    }
    // 4. Imprime o cabeçalho com os números dos lugares (01 02 03 ...)
    printf("  "); // Espaço para alinhar com as letras das fileiras
    for (int j = 0; j < Lugares; j++) {
        printf(" %02d", j + 1);
    }
    printf("\n");
    // 5. Imprime as fileiras da última até a primeira
    for (int i = Fileiras - 1; i >= 0; i--) {
        printf("%c ", 'A' + i); // Letra da fileira
        for (int j = 0; j < Lugares; j++) {
            printf("%s ", sala[i][j]); // Imprime o estado do assento
        }
        printf("\n");
    }
    return 0;
}