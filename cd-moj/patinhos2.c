#include <stdio.h>

#define MAX 1002

char mapa[MAX][MAX];
int visitado[MAX][MAX];
int m = 0, n = 0;
int buracos = 0;
int achei = 0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) {
    if (mapa[x][y] == 'E') {
        achei = 1;
        return;
    }
    visitado[x][y] = 1;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visitado[nx][ny]) {
            if (mapa[nx][ny] == '#' ) continue;
            if (mapa[nx][ny] == 'o') {
                buracos++;
                mapa[nx][ny] = '_'; // Preenche o buraco
            }
            dfs(nx, ny);
            if (achei) return;
        }
    }
}

int main() {
    int P;
    scanf("%d\n", &P);

    // Lê o mapa
    while (fgets(mapa[m], MAX, stdin) != NULL) {
        int len = 0;
        while (mapa[m][len] != '\n' && mapa[m][len] != '\0') len++;
        mapa[m][len] = '\0';
        m++;
    }
    n = 0;
    while (mapa[0][n] != '\0') n++;

    // Encontra o S
    int sx = -1, sy = -1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (mapa[i][j] == 'S') {
                sx = i;
                sy = j;
            }

    dfs(sx, sy);

    if (!achei || P - buracos <= 0)
        printf("Todos morreram :)\n");
    else if (buracos == 0)
        printf("Nenhum morreu :(\n");
    else
        printf("%d encontraram o vovo\n", P - buracos);

    return 0;
}