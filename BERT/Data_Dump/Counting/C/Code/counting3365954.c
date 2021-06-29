#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VMAX 10000 
#define M 2000001

int main()
{
  unsigned short *A, *B;

  int S[VMAX + 1];
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short) * n + 1);
  B = malloc(sizeof(short) * n + 1);

  for(i = 0; i <= VMAX; i++)
      S[i] = 0;
   
  for(i = 0; i < n; i++)
      scanf("%d",&A[i + 1]);
      
  for(i = 0; i < n; i++)
    S[A[i + 1]]++;
  
  for(i = 1; i <= VMAX; i++)
    S[i] = S[i] + S[i - 1];
 
  for(j = 1; j <= n; j++){
    B[S[A[j]]] = A[j];
    S[A[j]]--;
  }
 
  for(i = 1; i <= n; i++){
      if(i > 1)
	printf(" ");
      printf("%d", B[i]);
    }
  printf("\n");
  
  return 0;
}

