#include <stdio.h>

#define N 100

void trace(int A[], int length, int index) {
  int i;
  for (i = 0; i < length -1; i++) {
    printf("%d ", A[i]);
  }
  printf("%d\n", A[i]);
  printf("%d\n", index);
}


int main() {
  int length, i, j, tmp, minj;
  int index = 0;
  int A[N];
  scanf("%d", &length);
  for (i = 0; i < length; i++) {
    scanf("%d", &A[i]);
  }
  for (i = 0; i < length; i++) {
    minj = i;
    for (j = i; j < length; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
      tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
      if (A[i] != A[minj]) {
        index++;
      }
      }
  trace(A, length, index);
  return 0;
}
