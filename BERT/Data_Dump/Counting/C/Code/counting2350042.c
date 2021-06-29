#include <stdio.h>

#define MAX 2000001
#define NMAX 10000

int n;
int A[MAX], B[MAX], C[NMAX+1];

void countingSort() {
  int i, j;

  for (i = 0; i <= NMAX; i++) {
    C[i] = 0;
  }

  for (j = 1; j <= n; j++) {
    C[A[j]]++;
  }

  for (i = 1; i <= NMAX; i++) {
    C[i] = C[i] + C[i-1];
  }

  for (j = 1; j <= n; j++) {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

}

int main() {
  int i;

  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
  }

  countingSort();

  for (i = 1; i <= n; i++) {
    if (i == n) {
      printf("%d\n", B[i]);
      break;
    }
    printf("%d ", B[i]);
  }

  return 0;
}
