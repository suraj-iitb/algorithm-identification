#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main()
{
  unsigned short *A,*B;

  int C[VMAX+1];
  int n,i,j,x = 0,k;

  scanf("%d",&n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);


  for(i = 1;i <= n;i++){
    scanf("%hu",&A[i]);
    if(x < A[i]) x = A[i];
  }

  k = x;

  for( i = 0;i <= k;i++)
    C[i] = 0;

     /* C[i] に i の出現数を記録する */
  for( j = 1 ; j <= n;j++)
    C[A[j]]++;

     /* C[i] に i 以下の数の出現数を記録する*/
  for (i = 1 ;i <= k;i++)
    C[i] = C[i] + C[i-1];

  for (j = n;j > 0;j--){
	      
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  printf("%u",B[1]);
  for(i = 2;i <= n;i++){
    printf(" %u",B[i]);
  }
  printf("\n");
  


  return 0;
}


