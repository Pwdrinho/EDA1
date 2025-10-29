#include <stdio.h>
#include <string.h>

void trocaXporY(char *str) {
    if (*str == '\0') return;
    if (*str == 'x') *str = 'y';
    trocaXporY(str + 1);
}

void trim_end(char *s) {
    size_t n = strlen(s);
    if (n == 0) return;
    if (s[n - 1] == '\n' || s[n - 1] == '\r') {
        s[n - 1] = '\0';
        trim_end(s);
    }
}

void process_all(void) {
    char str[85];
    if (!fgets(str, sizeof str, stdin)) return;
    trim_end(str);
    trocaXporY(str);
    printf("%s\n", str);
    process_all();
}

int main(void) {
    process_all();
    return 0;
}