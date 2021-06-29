#include <stdio.h>
#include <stdlib.h>

#define N 2000001

void CountingSort(int *, int *, int);

int n;

int main () {
  int *A, i, *B, k = 0;

  scanf("%d",&n);  
  A = (int *)malloc(sizeof(int) * N);
  B = (int *)malloc(sizeof(int) * N);

  for(i = 1; i <= n ; i++) {
    scanf("%d",&A[i]);
    if(k < A[i]) k = A[i];
  }
  
  CountingSort(A, B, k);

  for(i = 1 ; i <= n ; i++) {
    if(i < n)printf("%d ",B[i]);
    else printf("%d\n",B[i]);
  }
  
  free(A);
  free(B);
  
  return 0;
}


void CountingSort(int A[], int B[], int k) {
  int C[10000], i, j;

  for(i = 0 ; i <= k ; i++) C[i] = 0;

  for(j = 1 ; j <= n ; j++) {
    C[A[j]]++;
  }
  
  
  for(i = 1 ; i <= k ; i++) {
    C[i] = C[i] + C[i-1];
  }


  for(j = n ; j >= 1 ; j--) {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

