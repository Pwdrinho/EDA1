#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x, *ptrx, **pptrx;
  
  //inicializando a variavel com zero
  x = 0;
  printf("\nvalor de x = %d\n", x);
  printf("Endereco de x: %p\n\n",&x);
  
  
  //Atribuindo os enderecos para os ponteiros
  ptrx = &x; // ptrx aponta para x
  pptrx = &ptrx; // pptrx aponta para ptrx    
    
  *ptrx = *ptrx + 10;
  printf("\nvalor de x = %d", x);
  printf("\nEndereco apontado por ptrx: %p\n",ptrx);
  printf("Valor da variavel X que esta sendo apontada por ptrx: %d\n",*ptrx);
  printf("Endereco de memoria da variavel ptrx %p\n",&ptrx); 
 
  **pptrx = **pptrx + 10;
  printf("\n\nvalor de x = %d", x);
  printf("\nEndereco apontado por **pptrx: %p",pptrx);
  printf("\nValor da variavel para a qual pptrx faz referencia: %d",**pptrx);
  printf("\nEndereco de memoria da variavel **pptrx %p\n\n",&pptrx);
  
   
  return 0;
}