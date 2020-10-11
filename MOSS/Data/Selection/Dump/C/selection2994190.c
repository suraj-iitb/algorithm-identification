#include<stdio.h>

void trace(int A[], int N){
  int i;
  for ( i = 0; i < N; i++ ){
    if (i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void selectionSort(int A[], int N) {
  int k, i, j, minj, m;
  m = 0;
  for ( i = 0; i < N; i++ ) {
    minj = i;
    for ( j = i; j < N; j++ ) {
      if ( A[j] < A[minj] ) {
	minj = j;
      }
    }
    if (A[i] != A[minj]) {
      k = A[i];
      A[i] = A[minj];
      A[minj] = k;
      m++;
    }
  }
  trace(A, N);
  printf("%d\n", m);
}

int main(){
  int A[100], N, i;

  scanf("%d", &N);

  for ( i = 0; i < N; i++ ) scanf("%d", &A[i]);
  
  selectionSort(A, N);
  return 0;
}

