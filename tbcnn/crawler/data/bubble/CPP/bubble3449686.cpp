#include<stdio.h>

int bubbleSort(int A[], int N) {
  int cnt = 0;
  for ( int i = 0; i < N; i++ ) {
    for ( int j = N - 1; j > i; j-- ) {
      if ( A[j] < A[j - 1]) {
        int t = A[j]; A[j] = A[j - 1]; A[j - 1] = t;
        cnt++;
      }
    }
  }
  return cnt;
}



int main() {
  int N, cnt = 0;
  int A[100];

  scanf("%d", &N);
  for ( int i = 0; i < N; i++ ) scanf("%d", &A[i]);

  cnt = bubbleSort(A, N);

  for ( int i = 0; i < N; i++ ) {
    if ( i ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");

  printf("%d\n", cnt);

  return 0;
}

