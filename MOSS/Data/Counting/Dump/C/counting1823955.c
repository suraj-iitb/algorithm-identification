#include<stdio.h>
#define cmax 10000

int main(){
  int i,n,j;
  int C[cmax];
    scanf("%d",&n);
  unsigned short A[n],B[n];
  
  
  for( i = 1 ; i <= n ; i++ )
    scanf("%hu",&A[i]);
    
  for( i = 0 ; i <= cmax ; i++ )
    C[i] = 0;

  for( j = 1 ; j <= n ; j++ )
    C[A[j]]++;

  for( i = 1 ; i <= cmax ; i++ )
    C[i] = C[i] + C[i-1];

  for( j = n ; j > 0 ; j-- )
    {
      B[C[A[j]]] = A[j];
      C[A[j]]--;
    }


  for( i = 1 ; i < n ; i++ )
    printf("%d ",B[i]);
  printf("%d\n",B[i]);
  return 0;
}
