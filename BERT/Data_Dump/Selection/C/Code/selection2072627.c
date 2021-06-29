#include <stdio.h>

int main(void) {
  int i, j, k = 0, t;
  int N, A[100], minj; 

  scanf("%d", &N);

  for (i = 0 ; i < N ; i++) 
    scanf ("%d", &A[i]);

  for (i = 0 ; i < N-1 ; i++) {
    minj = i;
    for (j = i ; j < N ; j++) {
      if (A[j] < A[minj])
        minj = j;
    }
    t = A[i];
    A[i] = A[minj];
    A[minj] = t;
    if (i != minj)
      k++;
  }

  for (i = 0 ; i < N ; i++){
    if (i > 0)
      printf(" "); 
    printf ("%d", A[i]);
  }
  putchar ('\n');
  printf ("%d\n", k);

  return 0;
}
