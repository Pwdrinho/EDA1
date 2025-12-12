// Esta função recebe um vetor v[0..n-1]
// e um índice k tal que 0 <= k < n.
// Ela devolve v[k] e remove esse
// elemento do vetor.

int remove_r (int k, int n, int v[]) {
   int x = v[k];
   if (k < n-1) {
      int y = remove_r (k+1, n, v); 
      v[k] = y;
   }
   return x;
}