#include<stdio.h>

int main() {
  int i, j, N, A[100], key, k;

  scanf("%d", &N);

  for(i = 0; i < N; i++) scanf("%d", &A[i]);

  for(i = 1; i <= N - 1; i++) {
    for(k = 0; k < N; k++) {
      printf("%d", A[k]);
      if(k == N - 1) printf("\n");
      if(k != N - 1) printf(" ");
    }
    key = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > key) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;
  }
  for(k = 0; k < N; k++) {
    printf("%d", A[k]);
    if(k == N - 1) printf("\n");
    if(k != N - 1) printf(" ");
  }

  return 0;
}

