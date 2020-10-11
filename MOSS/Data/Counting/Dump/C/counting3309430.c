#include <stdio.h>
#include <stdlib.h>
void CountingSort(int *, int * , int);
int n, *C;
int main()
{
  int i, *A, *B;

  scanf("%d",&n);
  A = (int *)malloc((n+1) * sizeof(int));
  B = (int *)malloc((n+1) * sizeof(int));
  C = (int *)malloc(10001 * sizeof(int));
  
  for(i = 1 ; i <= n ; i++) scanf("%d",&A[i]);

  /*for(i = 0 ; i <= n-1 ; i++) CountingSort(A, B, i);*/
  CountingSort(A, B, 10000);

  for(i = 1 ; i < n ; i++) printf("%d ",B[i]);
  printf("%d\n",B[n]);
  
  free(A);
  free(B);
  free(C);
  
  return 0;
}

void CountingSort(int *A, int *B, int k)
{
  int i, j;

  for(i = 0 ; i <= k ; i++) C[i] = 0;

  for(j = 1 ; j <= n ; j++) C[A[j]]++;

  for(i = 1 ; i <= k ; i++) C[i] = C[i] + C[i-1];

  for(j = n ; j >= 1 ;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--; }

}
