#include <stdio.h>
#include <stdlib.h>

void insertion(int **v, int n) {
    for (int j = 1; j < n; j++) {
        
        int id = v[j][0];
        int nivel = v[j][1];
        int status = v[j][2];
        
        int i = j - 1;

        while (i >= 0 && (v[i][1] < nivel || (v[i][1] == nivel && v[i][2] < status))) {
            v[i + 1][0] = v[i][0];
            v[i + 1][1] = v[i][1];
            v[i + 1][2] = v[i][2];
            i--;
        }        
        v[i + 1][0] = id;
        v[i + 1][1] = nivel;
        v[i + 1][2] = status;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int **v;
    v = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        v[i] = malloc(3 * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &v[i][0], &v[i][1], &v[i][2]);
    }

    insertion(v, n);

    for (int i = 0; i < n; i++) {
        printf("%.4d | %d | %d\n", v[i][0], v[i][1], v[i][2]);
    }

    for (int i = 0; i < n; i++) {
        free(v[i]);
    }

    free(v);
    return 0;
}