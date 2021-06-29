#include <stdio.h>

int main(){

  int i, j, N;
  int A[100];
  int temp, min, c=0;

  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  for (i = 0; i < N-1; i++) {
    min = i;
    for (j = i; j < N; j++) {
      if(A[j] < A[min]) min = j;
    }
    temp = A[i];
    A[i] = A[min];
    A[min] = temp;
    if(i != min) c++;
  }


  for (i = 0; i < N-1; i++) {
    printf("%d ", A[i]);
  }
  printf("%d\n", A[N-1]);
  printf("%d\n", c);

  return 0;
}

