#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

void CountingSort(int *, int *, int *, int);

int main(){
  int *A, *B;
  int C[VMAX+1];
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);

  /* your code */
  for (i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
  }

  CountingSort(A, B, C, n);

  for (i = 1; i <= n; i++) {
    printf("%d", B[i]);
    if (i == n) {
      printf("\n");
    }
    else {
      printf(" ");
    }
  }

  return 0;
}


void CountingSort(int *a, int *b, int *c, int n) {
  int i, j;

  for (i = 0; i <= VMAX; i++) {
    c[i] = 0;
  }

  for (j = 1; j <= n; j++) {
    c[a[j]]++;
  }

  for (i = 1; i <= VMAX; i++) {
    c[i] = c[i] + c[i-1];
  }

  for (j = n; j > 0; j--) {
    b[c[a[j]]] = a[j];
    c[a[j]]--;
  }

}

