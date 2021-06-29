#include<stdio.h>

int selectionSort(int A[], int N) {
  int cnt = 0;
  for ( int i = 0; i < N; i++ ) {
    int min = i;
    for ( int j = i; j < N; j++ ) {
      if ( A[min] > A[j]) min = j;
    }
    if ( min != i ) {
      int t = A[min]; A[min] = A[i]; A[i] = t;
      cnt++;
    }
  }
  return cnt;
}



int main() {
  int N, cnt = 0;
  int A[100];

  scanf("%d", &N);
  for ( int i = 0; i < N; i++ ) scanf("%d", &A[i]);

  cnt = selectionSort(A, N);

  for ( int i = 0; i < N; i++ ) {
    if ( i ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");

  printf("%d\n", cnt);

  return 0;
}

