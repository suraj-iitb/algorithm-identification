#include <stdio.h>
#define M 100

int k = 0;

void swap (int *x, int *y) {
  int temp;    // 値を一時保存する変数

  temp = *x;
  *x = *y;
  *y = temp;
}

/* バブルソート */
void bubble_sort(int A[], int N) {
  int i, j;

  for (i = 0; i < N - 1; i++){
    for (j = N - 1; j >= i + 1; j--){   //　右から左に操作
      if (A[j] < A[j-1]) { swap(&A[j], &A[j-1]); k += 1; }
    }
  }
}

int main (void) {
  int A[M];
  int i;
  int N;
  scanf("%d", &N);
  for(i = 0; i < N; i++){scanf("%d", &A[i]);}

  bubble_sort(A, N);

  for (i = 0; i < N; i++){
    if(i == 0)printf("%d", A[i]);
    else printf(" %d", A[i]);}
  printf("\n%d\n", k);

  return 0;
}

