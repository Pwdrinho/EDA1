#include <stdio.h>

/**
 * @brief Verifica se um caractere é uma vogal maiúscula.
 *
 * @param c O caractere a ser verificado.
 * @return 1 se for vogal, 0 caso contrário.
 */
int ehVogal(char c) {
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return 1;
    }
    return 0;
}

/**
 * @brief Conta recursivamente o número de vogais em uma string.
 * Esta é a função do "Amigo que se Liga para Pedir Ajuda".
 *
 * @param s A string (ou o que restou dela).
 * @return O número total de vogais encontradas.
 */
int contaVogaisRecursivo(const char *s) {
    // Caso Base: "O amigo recebeu uma palavra vazia".
    // Se o caractere atual é o terminador nulo ('\0'), não há mais letras.
    // Ele retorna 0 para quem o chamou.
    if (*s == '\0') {
        return 0;
    }

    // Passo Recursivo: "O amigo faz sua parte e liga para o próximo".
    
    // 1. Ele verifica sua primeira letra e anota o resultado (0 ou 1).
    int vogalNaLetraAtual = ehVogal(*s);
    
    // 2. Ele liga para o próximo amigo, passando o resto da palavra (s + 1),
    //    e espera pelo resultado.
    int vogaisNoRestoDaPalavra = contaVogaisRecursivo(s + 1);
    
    // 3. Ele soma seu resultado com o do amigo e retorna o total.
    return vogalNaLetraAtual + vogaisNoRestoDaPalavra;
}

int main() {
    // A string de entrada tem no máximo 100 caracteres.
    // Precisamos de 101 posições para incluir o caractere nulo '\0'.
    char palavra[101];

    // Lê a palavra da entrada.
    scanf("%100s", palavra);

    // Joãozinho inicia a "cadeia de ligações" passando a palavra completa.
    int totalDeVogais = contaVogaisRecursivo(palavra);

    // Imprime o resultado final.
    printf("%d\n", totalDeVogais);

    return 0;
}