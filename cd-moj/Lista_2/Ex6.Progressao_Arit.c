#include <stdio.h>

/**
 * @brief Verifica recursivamente se uma sequência de elementos em um vetor forma uma 
 * Progressão Aritmética (PA) de acordo com a definição fornecida.
 *
 * A verificação baseia-se na propriedade de que a soma dos elementos equidistantes 
 * dos extremos é constante. A função compara a soma do par de elementos mais externo
 * do segmento atual com a soma do próximo par de elementos internos. Se forem iguais, 
 * o processo continua recursivamente para o segmento interior.
 *
 * @param v Ponteiro para o vetor de inteiros.
 * @param primeiro Índice do primeiro elemento do segmento do vetor a ser analisado.
 * @param ultimo Índice do último elemento do segmento do vetor a ser analisado.
 * @return Retorna 1 se o segmento do vetor representa uma PA; caso contrário, retorna 0.
 */
int pa_recursiva(int *v, int primeiro, int ultimo) {
    // --- Caso Base (Condição de Parada) ---
    // Se o índice 'primeiro' avançou o suficiente para que não haja mais um par interno
    // para comparar (ou seja, quando restam apenas dois elementos no segmento), 
    // significa que todas as verificações anteriores foram bem-sucedidas.
    // A condição (primeiro >= ultimo - 1) cobre o caso final de verificação.
    if (primeiro >= ultimo - 1) {
        return 1; // A sequência é uma PA.
    }

    // --- Passo Recursivo ---
    // Verifica se a soma do par mais externo do segmento atual é igual à soma
    // do par imediatamente interno a ele.
    if ((v[primeiro] + v[ultimo]) != (v[primeiro + 1] + v[ultimo - 1])) {
        // Se as somas forem diferentes, a propriedade da PA é violada.
        return 0; // A sequência não é uma PA.
    }

    // Se a verificação do par atual passou, a função chama a si mesma para
    // o segmento interno do vetor, movendo os limites para dentro.
    return pa_recursiva(v, primeiro + 1, ultimo - 1);
}