#include <stdio.h>

int main(){
    int v[99];
    int i;
    for (i = 0; i < 99; ++i) {
        v[i] = 98 - i;
        printf("%d ", v[i]);
    }
    for (i = 0; i < 99; ++i) {
        v[i] = v[v[i]];
        printf("%d ", v[i]);
    }

    return 0;
}