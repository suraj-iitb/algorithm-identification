#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

void CountingSort(int *, int *, int);

int main()
{
  int *A, *B;
  int i;
  int n;  

  scanf("%d", &n);

  A = malloc(sizeof(int)*(n + 1));
  B = malloc(sizeof(int)*(n + 1));
  
  for( i = 1 ; i <= n ; i++ )
    scanf("%d", &A[i]);
  
  CountingSort(A, B, n);

  for( i = 1 ; i <= n ; i++ ){
    if( i > 1 ) printf(" ");
    printf("%d", B[i]);
  }
  
  printf("\n");

  free(A);
  free(B);
  
  return 0;
}
  
void CountingSort(int A[], int B[], int n)
{
  int i, j;
  int C[MAX+1];
  
  for( i = 0 ; i <= MAX ; i++ )
    C[i] = 0;
  
  for( j = 1 ; j <= n ; j++ )
    C[A[j]]++;

  for( i = 1 ; i <= MAX ; i++ )
    C[i] = C[i] + C[i-1];

  for( j = n ; j > 0 ; j-- ){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
  
