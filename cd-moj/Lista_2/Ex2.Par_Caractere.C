#include <stdio.h>
#include <string.h>

int contarParesRecursivo(const char *s) {
    if (strlen(s) < 3) {
        return 0;
    }
    // Passo Recursivo:
    // 1. Verifica se os caracteres nas posições 0 e 2 formam um par.
    int parEncontradoNestaEtapa = 0;
    if (s[0] == s[2]) {
        parEncontradoNestaEtapa = 1;
    }
    // 2. Soma o resultado desta etapa com o resultado da chamada recursiva
    //    para o resto da string. Em C, passar "s + 1" move o ponteiro
    //    para o próximo caractere, efetivamente processando a sub-string.
    return parEncontradoNestaEtapa + contarParesRecursivo(s + 1);
}
int main() {
    // Declara um array de caracteres para armazenar a string.
    // O tamanho 201 acomoda 200 caracteres mais o caractere nulo ('\n') de terminação.
    char stringDeEntrada[201];
    scanf("%200s", stringDeEntrada);
    int quantidadeDePares = contarParesRecursivo(stringDeEntrada);

    printf("%d\n", quantidadeDePares);

    return 0;
}