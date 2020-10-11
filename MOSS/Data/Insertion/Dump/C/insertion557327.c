#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
  int i, j, N;
  signed int tmp, *A;
  scanf("%d", &N);

  /* 整数Ｎ個を要素に持つ配列を確保する */
  A = (int *) malloc(sizeof(int) * N);

  for (i = 0; i < N; i++) 
    scanf(" %d", &A[i]);
 
  for (i = 0; i < N - 1; i++) 
    printf("%d ", A[i]);

  printf("%d\n", A[N - 1]);
 
  /* 挿入ソート */
  for (i = 1; i < N; i++) { 
    
    tmp = A[i];
    
    /* iから始める */
    j = i;
    
    /* A[j] < A[j - 1] であれば要素を入れ替えて、jをデクリメント */
    while (A[j] < A[j - 1] && j > 0) {
      A[j]     = A[j - 1];
      A[j - 1] = tmp;
      j--;
    }
    
    for (j = 0; j < N - 1; j++) 
      printf("%d ", A[j]);
    
    printf("%d\n", A[N - 1]);
  }
  return 0;
}
