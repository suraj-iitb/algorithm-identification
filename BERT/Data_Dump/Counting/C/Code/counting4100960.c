#include<stdio.h>
#include<stdlib.h>

#define N 2000000
#define AMAX 10000

int main()
{
  int n,i,j;
  int *A,*B;
  int C[AMAX+1]; /* Aに入力,Bで出力,Cに記録*/

  scanf("%d",&n);

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);  /* A,Bのメモリ確保 */

  for(i=0;i<=AMAX;i++)
    C[i] = 0;

  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
    C[A[i+1]]++;
  }

  for(i=1;i<=AMAX;i++)
    C[i] = C[i] + C[i-1];

  for(j=1;j<=n;j++){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i=1;i<=n;i++){
    if(i > 1){
      printf(" ");
    }
    printf("%d",B[i]);
      }

  printf("\n");

  return 0;
}

  

