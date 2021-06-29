#include <stdio.h>
void showA(int A[], int N) {
  int i;
  for (i = 0; i < N; ++i) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int bubbleSort(int A[], int N) {
  int flag = 1;
  int i, j, cnt, tmp;

  cnt = 0;
    for (i = 0; i < N - 1; ++i){
      for (j = N - 1; j - i > 0 ; --j) {
	if (A[j - 1] > A[j]) {
	  tmp = A[j];
	  A[j] = A[j - 1];
	  A[j - 1] = tmp;
	  ++cnt;
	  //	  showA(A, N);
	}
      }
  }

  return cnt;
}

int main(void) {
  int n, i;
  int cnt;
  int A[100] = {0};
  n = 0;
  scanf("%d", &n);

  for (i = 0; i < n; ++i) {
    scanf("%d", &A[i]);
  }
  cnt = bubbleSort(A, n);

  for (i = 0; i < n; ++i) {
    if (i < n -1) {
      printf("%d ", A[i]);
    } else {
      printf("%d\n", A[i]);
    }
  }
  printf("%d\n", cnt);
  
  return 0;
}
