#include<stdio.h>

int main() {
  int flag, i, N, tmp, count, A[100];
  flag = 1;
  count = 0;
  scanf("%d", &N);
  for ( i = 0; i < N; i++ ) scanf("%d", &A[i]);
  while (flag) {
    flag = 0;
    for ( i = N - 1; i > 0; i-- ) {
      if ( A[i-1] > A[i] ) {
        tmp = A[i];
        A[i] = A[i-1];
        A[i-1] = tmp;
        flag = 1;
        count++;
      }
    }
  }
  for (i = 0; i < N; i++ ) {
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", count);
  return 0;
}

