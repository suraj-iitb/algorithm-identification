#include<stdio.h>

int main() {
  int N, i, value;
  int A[100];

  scanf("%d", &N);
  for ( i = 0; i < N; i++ ) scanf("%d", &A[i]);

  for ( i = 0; i < N; i++ ) {
    int j, k;

    value = A[i];
    j = i - 1;

    while ( j >= 0 && A[j] > value ) {
      A[j + 1] = A[j];
      j--;
    }

    A[j+1] = value;

    for ( k = 0; k < N; k++ ) {
      if ( k > 0 ) printf(" ");
      printf("%d", A[k]);
    }

    printf("\n");
  }

  return 0;
 }
