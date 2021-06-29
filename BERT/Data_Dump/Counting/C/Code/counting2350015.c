#include <stdio.h>

void CountingSort(int *, int *, int);

int n;

int main(){
  int *A;
  int *B;
  int i;

  scanf("%d", &n);

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);
  
  for(i=1; i<=n; i++) scanf("%d", &A[i]);

  CountingSort(A, B, 10000);

  for(i=1; i<n; i++) printf("%d ", B[i]);
  printf("%d\n", B[i]);
  
  return 0;
}

void CountingSort(int *A, int *B, int k){
  int i, j;
  int C[k+1];

  for(i=0; i<=k; i++) C[i] = 0;
  for(j=1; j<=n; j++) C[A[j]]++;
  for(i=1; i<=k; i++) C[i] += C[i-1];
  for(j=n; j>=1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
