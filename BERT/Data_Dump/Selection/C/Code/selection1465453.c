#include <stdio.h>

#define SIZE 128

int N;
int selectionSort(int *A);

int main(void){
  int i, A[SIZE] ={0};
  scanf("%d", &N);
  for (i = 0; i < N; i++)
    scanf("%d", &A[i]);
  int cnt = selectionSort(A);

  for (i = 0; i < N; i++) {
    printf("%d", A[i]);
    if (i < N - 1)
      printf(" ");
  }
  printf("\n%d\n", cnt);
  return 0;
}

int selectionSort(int *A){
  int i, j, minj, tmp, cnt = 0;
  for (i = 0; i < N; i++) {
    minj = i;
    for (j = i; j < N; j++) {
      if (A[j] < A[minj])
	minj = j;
    }
    if (A[i] != A[minj]) {
      tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
      cnt++;
    }
  }
  return cnt;
}
