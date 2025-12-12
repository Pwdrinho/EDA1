// Esta função recebe um vetor v[0..n-1]
// e um índice k tal que 0 <= k < n.
// Ela devolve v[k] e remove esse
// elemento do vetor.

int
remove (int k, int n, int v[])
{
   int x = v[k];
   for (int j = k+1; j < n; ++j)  
      v[j-1] = v[j];
   return x;
}