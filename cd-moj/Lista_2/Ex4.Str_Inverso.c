#include <stdio.h>

/**
 * @brief Imprime uma string ao contrário na tela usando recursão.
 * * A função opera processando o resto da string primeiro e depois
 * imprimindo o caractere atual, invertendo a ordem de impressão.
 * * @param s Um ponteiro para o início da string a ser impressa.
 */
void imprimeReverso(const char *s) {
    // Caso Base: Se o caractere apontado por 's' é o terminador nulo ('\0'),
    // significa que chegamos ao final da string. A função não faz nada e retorna.
    if (*s == '\0') {
        return;
    }

    // Passo Recursivo:
    // 1. Chama a função para o resto da string.
    //    's + 1' é um ponteiro para o próximo caractere.
    imprimeReverso(s + 1);

    // 2. Imprime o caractere atual.
    //    Esta linha só é executada DEPOIS que a chamada recursiva acima
    //    tiver retornado. Isso garante que o último caractere seja impresso
    //    primeiro, seguido pelo penúltimo, e assim por diante.
    putchar(*s);
}

int main() {
    // Declara um array de caracteres para armazenar a string de entrada.
    // O tamanho 501 acomoda 500 caracteres mais o caractere nulo ('\0').
    char stringDeEntrada[501];

    // Lê a string da entrada padrão, com um limitador para evitar buffer overflow.
    scanf("%500s", stringDeEntrada);

    // Chama a função recursiva para imprimir a string ao contrário.
    imprimeReverso(stringDeEntrada);

    // A saída do problema requer uma única linha, então adicionamos
    // o caractere de nova linha no final do processo.
    printf("\n");

    return 0;
}