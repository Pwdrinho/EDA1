#include <stdio.h>

#define TAM 8

int dX[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dY[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

typedef struct {
    int x, y, distancia;
} No;

// Busca em largura para achar o menor caminho
int bfs(int xInicial, int yInicial, int xFinal, int yFinal) {
    int visitado[TAM][TAM] = {0};
    No fila[1000];
    int inicio = 0, fim = 0;

    fila[fim++] = (No){xInicial, yInicial, 0};
    visitado[xInicial][yInicial] = 1;

    while (inicio < fim) {
        No atual = fila[inicio++];

        // Se chegou ao destino, retorna a distância
        if (atual.x == xFinal && atual.y == yFinal)
            return atual.distancia;

        // Tenta todos os movimentos do cavalo
        for (int i = 0; i < 8; i++) {
            int nx = atual.x + dX[i];
            int ny = atual.y + dY[i];

            if (nx >= 0 && nx < TAM && ny >= 0 && ny < TAM && !visitado[nx][ny]) {
                visitado[nx][ny] = 1;
                fila[fim++] = (No){nx, ny, atual.distancia + 1};
            }
        }
    }

    return -1;
}

void converter(char posicao[], int *x, int *y) {
    *x = posicao[0] - 'a';
    *y = posicao[1] - '1';
}

int main() {
    char origem[3], destino[3];

    while (scanf("%s %s", origem, destino) != EOF) {
        int xIni, yIni, xFim, yFim;

        converter(origem, &xIni, &yIni);
        converter(destino, &xFim, &yFim);

        int movimentos = bfs(xIni, yIni, xFim, yFim);

        printf("To get from %s to %s takes %d knight moves.\n",
               origem, destino, movimentos);
    }

    return 0;
}
