#include <stdio.h>

// Recebe x, n >= 0 e v e devolve k
// tal que 0 <= k < n e v[k] == x. 
// Se tal k não existe, devolve -1

int busca_r (int x, int n, int v[]) {
   if (n == 0) return -1;
   if (x == v[n-1]) return n-1;
   return busca_r (x, n-1, v);
}