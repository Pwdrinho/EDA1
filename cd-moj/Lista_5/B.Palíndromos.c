#include <stdio.h>
#include <string.h>

int main() {
    int N;
    char s[1001];

    scanf("%d", &N);
    scanf("%s", s);

    int i = 0;
    int j = N - 1;

    while (i < j) {
        if (s[i] != s[j]) {
            printf("0\n");
            return 0;
        }
        i++;
        j--;
    }

    printf("1\n");
    return 0;
}