#include <stdio.h>

/**
 * @brief Calcula o n-ésimo termo da sequência de Fibonacci de forma eficiente
 * usando recursão com memoization.
 *
 * @param n O número do termo da série a ser retornado (1 <= n <= 80).
 * @return O valor do n-ésimo termo de Fibonacci como um long long int.
 */
long long int fibonacci(int n) {
    // Vetor para armazenar os resultados já calculados.
    // 'static' garante que o vetor seja inicializado com zeros apenas uma vez
    // e persista entre as chamadas da função.
    // Usamos tamanho 81 para podermos usar o índice n diretamente (1 a 80).
    static long long int memo[81] = {0};

    // Casos base da sequência de Fibonacci.
    // F(1) = 1, F(2) = 1.
    if (n <= 2) {
        return 1;
    }

    // Se o valor para 'n' já foi calculado, retorna-o do vetor.
    // Isso evita o recálculo e torna a função eficiente.
    if (memo[n] != 0) {
        return memo[n];
    }

    // Se o valor não foi calculado, calcula-o recursivamente,
    // armazena o resultado no vetor e depois o retorna.
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    
    return memo[n];
}