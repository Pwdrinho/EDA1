// A função recebe x, n >= 0 e v e devolve
// um índice k em 0..n-1 tal que x == v[k]. 
// Se tal k não existe, devolve -1.

int busca (int x, int n, int v[]) {
    int k;
    for (k = n-1; k >= 0; --k) {
        if (v[k] == x) return k;
    }
    return -1; 
}