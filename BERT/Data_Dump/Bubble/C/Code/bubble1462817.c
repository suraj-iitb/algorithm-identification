#include <stdio.h>

#define SIZE 128

int N;
int bubbleSort(int *A);

int main(void){
  int i, A[SIZE] ={0};
  scanf("%d", &N);
  for (i = 0; i < N; i++)
    scanf("%d", &A[i]);
  int cnt = bubbleSort(A);

  for (i = 0; i < N; i++) {
    printf("%d", A[i]);
    if (i < N - 1)
      printf(" ");
  }
  printf("\n%d\n", cnt);
  return 0;
}

int bubbleSort(int *A){
  int flg = 1, i = 0, j, tmp, cnt = 0;
  while(flg) {
    flg = 0;
    for (j = N - 1; i < j; j--) {
      if (A[j] < A[j - 1]) {
	tmp = A[j];
	A[j] = A[j - 1];
	A[j - 1] = tmp;
	cnt++;
      }
      flg = 1;
    }
    i++;
  }
  return cnt;
}
