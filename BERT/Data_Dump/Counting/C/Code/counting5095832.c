#include <stdio.h>
#include <stdlib.h>
#define N 2000001
#define VMAX 10000
int main()
{
  unsigned short *A,*B;
  int n,i,j,C[2*N];
  scanf("%d",&n);
  

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);
  for(i = 0; i <= 2*n; i++)
    C[i] = 0;
  
  for(j = 1; j <= n; j++)
    {
      scanf("%hu",&A[j]);
      C[A[j]]++;
    }
  
  for(i = 1; i <= 2*n; i++)
    C[i] += C[i-1];
  
  for(j = n; j >= 1; j--)
    {
      B[C[A[j]]] = A[j];
      C[A[j]]--;
    }

  for(i = 1; i <= n; i++)
    {
      printf("%u",B[i]);
      if(i != n) printf(" ");
      else printf("\n");
    }
 
  
  return 0;
}
  

