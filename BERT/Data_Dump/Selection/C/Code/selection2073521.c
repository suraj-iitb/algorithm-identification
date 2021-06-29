#include<stdio.h>
int main () {
  int i, temp, a, minj, j, k = 0;
  int A[100];

  scanf("%d\n", &a);

  for (i = 0; i < a; i++) {
    scanf("%d", &A[i]);
  }

  for (i = 0; i < a - 1; i++) {
    minj = i;
    for (j = i; j < a; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;

    if (i != minj) {
      k++;
    }
  }

  for (i = 0; i < a; i++) {
    if (i > 0) {
      printf(" ");
    }
    printf("%d", A[i]);
  }

  printf("\n");
  printf("%d\n", k);

  return 0;
}
