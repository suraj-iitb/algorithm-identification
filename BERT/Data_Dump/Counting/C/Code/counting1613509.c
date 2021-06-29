#include <stdio.h>

#define N 2097152 // 2^21
#define MAXVAL 16384 // 2^14

int A[N] = {0}, B[N] = {0}, C[MAXVAL] = {0};

void countingSort(int n, int max) {
  int i;

  // count up
  for (i = 0; i < n; i++)
    C[A[i]]++;

  // calculate cumulative sum
  for (i = 1; i <= max; i++)
    C[i] += C[i - 1];

  for (i = n - 1; 0 <= i; i--) {
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
}

int main() {
  int i, n, max = 0;
  const char *sp;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
    if (max < A[i])
      max = A[i];
  }
  countingSort(n, max);
  for (i = 1, sp = ""; i < n + 1; i++) {
    printf("%s%d", sp, B[i]);
    sp = " ";
  }
  puts("");
  return 0;
}
