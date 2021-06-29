#include<stdio.h>
int main () {
  int i, a, v, j, k;
  int A[100];

  scanf("%d\n", &a);

  for (i = 0; i < a; i++) {
    scanf("%d", &A[i]);
    if (i > 0) {
      printf(" ");
    }
      printf("%d", A[i]);
  }
  printf("\n");

  for (i = 1; i < a; i++) {
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for (k = 0; k < a; k++) {
      if (k > 0) {
        printf(" ");
      }
      printf("%d", A[k]);
    }
    printf("\n");
  }

  return 0;
}
