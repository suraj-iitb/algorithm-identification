#include <stdio.h>

#define MAX_N 100

int bubbleSort(int A[], int N);

int main() {
  int N;
  int A[MAX_N];
  int cnt;
  int i;

  scanf("%d", &N);
  for(i = 0; i < N; ++i) scanf("%d", A+i);

  cnt = bubbleSort(A, N);
  for(i = 0; i < N; ++i) printf("%d%c", A[i], " \n"[i==N-1]);
  printf("%d\n", cnt);

  return 0;
}

int bubbleSort(int A[], int N) {
  int cnt = 0;
  int tmp;
  int flag = 1;
  int j;

  while(flag) {
    flag = 0;
    for(j = N-1; j > 0; --j) {
      if(A[j] < A[j-1]) {
        tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        flag = 1;
        ++cnt;
      }
    }
  }
  return cnt;
}


