#include<stdio.h>
#include<stdlib.h>

#define LIM 2000000
#define MAX 10000


int * countingSort(int A[], int n) {
  int B[MAX];
  int *C = (int *)malloc(sizeof(int) * n);
  
  for ( int i = 0; i < MAX; i++ ) B[i] = 0;
  for ( int i = 0; i < n; i++ ) B[A[i]]++;
  for ( int i = 1; i < MAX; i++ ) B[i] = B[i] + B[i - 1];

  for ( int i = n; i >= 0; --i ) {
    C[B[A[i]]] = A[i];
    B[A[i]]--;
  }
  return C;
}

int main() {
  int n, A[LIM], *C;
  C = (int *)malloc(sizeof(int) * n);

  scanf("%d", &n);
  for ( int i = 0; i < n; i++ ) scanf("%d", &A[i]);

  C = countingSort(A, n);
  for ( int i = 1; i <= n; i++ ) {
    if (i > 1) printf(" ");
    printf("%d", C[i]);
  }
  printf("\n");
  return 0;
}
