#include <stdio.h>

/**
 * @brief Conta recursivamente o número de ocorrências do dígito 7 em um inteiro.
 *
 * @param n O número (não negativo) a ser verificado.
 * @return A quantidade de vezes que o dígito 7 aparece em n.
 */
int conta_7s(long long n) {
    // --- Caso Base ---
    // Se n for 0, não há mais dígitos para verificar.
    if (n == 0) {
        return 0;
    }

    // --- Passo Recursivo ---
    // Pega o último dígito do número.
    int ultimo_digito = n % 10;

    // Verifica se o último dígito é 7.
    int contagem_atual = 0;
    if (ultimo_digito == 7) {
        contagem_atual = 1;
    }

    // Soma a contagem do dígito atual com a contagem dos dígitos restantes
    // (obtida pela chamada recursiva com o número dividido por 10).
    // --- Chamada Recursiva ---
    return contagem_atual + conta_7s(n / 10);
}

int main() {
    long long n;

    // Lê o número da entrada. O formato "%lld" é para long long.
    scanf("%lld", &n);

    // Chama a função recursiva e imprime o resultado.
    printf("%d\n", conta_7s(n));

    return 0;
}