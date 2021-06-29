#include <stdio.h>
#define N 2000001

int A[N], B[N], C[N];
int n;

void countingsort(int *, int *, int);

main() {
  int i, k = 0;

  scanf("%d", &n);

  for(i = 1; i < n + 1; i++) {
    scanf("%d", &A[i]);
  }
  for(i = 1; i < n + 1; i++) {
    if(A[i] > k) {
      k = A[i];
    }
  }
  k = k + 1;

  countingsort(A, B, k);

  for(i = 1; i < n + 1; i++) {
    if(i == n) {
      printf("%d\n", B[i]);
    }
    else {
      printf("%d ", B[i]);
    }
  }
  return 0;
}

void countingsort(int *A, int *B, int k) {
  int i, j;

  for(i = 0; i < k; i++) {
    C[i] = 0;
  }

  for(j = 1; j < n + 1; j++) {
    C[A[j]]++;
  }

  for(i = 1; i < k; i++) {
    C[i] = C[i] + C[i - 1];
  }

  for(j = n; j >= 1; j--) {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
