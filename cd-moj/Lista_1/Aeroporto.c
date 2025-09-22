#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char nomeAeroporto[100001];
    char sigla[4];

    scanf("%s", nomeAeroporto);
    scanf("%s", sigla);

    int lenNome = strlen(nomeAeroporto);
    int lenSigla = strlen(sigla);

    // Converter o nome do aeroporto para maiúsculas para comparação
    for (int i = 0; i < lenNome; i++) {
        nomeAeroporto[i] = toupper(nomeAeroporto[i]);
    }

    int siglaIndex = 0;
    int nomeIndex = 0;
    int matchCount = 0;

    if (sigla[2] == 'X') {
        // Caso 2: Sigla termina com 'X', verificar apenas os dois primeiros caracteres
        while (nomeIndex < lenNome && siglaIndex < 2) {
            if (nomeAeroporto[nomeIndex] == sigla[siglaIndex]) {
                matchCount++;
                siglaIndex++;
            }
            nomeIndex++;
        }
        if (matchCount == 2) {
            printf("Sim\n");
        } else {
            printf("Nao\n");
        }
    } else {
        // Caso 1: Sigla normal, verificar todos os três caracteres
        while (nomeIndex < lenNome && siglaIndex < lenSigla) {
            if (nomeAeroporto[nomeIndex] == sigla[siglaIndex]) {
                matchCount++;
                siglaIndex++;
            }
            nomeIndex++;
        }
        if (matchCount == lenSigla) {
            printf("Sim\n");
        } else {
            printf("Nao\n");
        }
    }

    return 0;
}
