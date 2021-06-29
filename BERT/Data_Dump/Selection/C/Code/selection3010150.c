#include <stdio.h>

#define MAX_N 100

int selectionSort(int A[], int N);

int main() {
  int N;
  int A[MAX_N];
  int cnt;
  int i;

  scanf("%d", &N);
  for(i = 0; i < N; ++i) scanf("%d", A+i);

  cnt = selectionSort(A, N);
  for(i = 0; i < N; ++i) printf("%d%c", A[i], " \n"[i==N-1]);
  printf("%d\n", cnt);

  return 0;
}

int selectionSort(int A[], int N) {
  int cnt = 0;
  int minj, tmp;
  int i, j;

  for(i = 0; i < N; ++i) {
    minj = i;
    for(j = i; j < N; ++j) {
      if(A[j] < A[minj]) minj = j;
    }
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
    cnt += minj != i;
  }
  return cnt;
}

