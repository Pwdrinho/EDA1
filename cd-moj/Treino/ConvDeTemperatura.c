#include <stdio.h>

int main() {
    char origem, destino;
    double temperatura;

    scanf(" %c", &origem);
    scanf(" %c", &destino);
    scanf("%lf", &temperatura);

    if (origem == 'F') {
        temperatura = (temperatura - 32) * 5.0 / 9.0;
    } 
    else if (origem == 'K') {
        temperatura = temperatura - 273.15;
    }

    if (destino == 'F') {
        temperatura = temperatura * 9.0 / 5.0 + 32;
    }
    else if (destino == 'K') {
        temperatura = temperatura + 273.15;
    }
    printf ("%.2lf\n", temperatura);
    return 0;
}