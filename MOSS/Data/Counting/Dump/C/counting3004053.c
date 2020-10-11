#include<stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000


/*void CountingSort(unsigned short *A, unsigned short *B, int k){
  int i,j;
  unsigned short C[VMAX];
  
  for (i = 0 ; i <= k ; i++)
    C[i] = 0;

  
  for (j = 1; i <= n; i++)
    C[A[j]]++;

  
 for (i = 1 ;i <= k;i++)
    C[i] = C[i] + C[i-1];

  for (j = n; j >= 1;j--){
    B[C[A[j]]] = A[j];
      C[A[j]]--;
      }
}*/


int main(){
  unsigned short *A, *B;
  int C[VMAX+1];
  int  i, j,n, k=0;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  /* your code */

  for(i=0;i<n;i++){
    scanf("%hu",&A[i+1]);
    
  }

  for (i = 0 ; i < VMAX ; i++)
    C[i] = 0;

  /* C[i] に i の出現数を記録する */
  for (j = 1; j <= n; j++){
    C[A[j]]++;
    
  }
  /* C[i] に i 以下の数の出現数を記録する*/
   for (i = 1 ;i < VMAX;i++)
    C[i] = C[i] + C[i-1];

  for (j = n; j >= 1;j--){
    B[C[A[j]]] = A[j];
      C[A[j]]--;
      }

   for(i=1;i<=n;i++){
     if(i!=1)
      printf(" ");
      
    printf("%u",B[i]);
   }
  printf("\n");
  free(A);
  free(B);


  return 0;
}

