#include <stdio.h>

long long int fibonacci(int n) {
    static long long int memo[81] = {0};

    // --- Casos base ---
    if (n <= 2) {
        return 1;
    }

    if (memo[n] != 0) {
        return memo[n];
    }
    // Passo Recursivo
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    
    // Chamada Recursiva
    return memo[n];
}