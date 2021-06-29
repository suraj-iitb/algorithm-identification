#include <stdio.h>

void swap(int *x, int *y){int t = *x; *x = *y; *y = t;}

int main(){
  int N, A[101], i, j, count = 0;
  scanf("%d", &N);
  for(i = 0; i < N; ++i) scanf("%d", A + i);

  for(i = 0; i < N; ++i)
    for(j = N - 1; j > i; --j)
      if(A[j] < A[j - 1]){
        swap(&A[j], &A[j - 1]);
        count = count+1;
      }

  for(i = 0; i < N; ++i) 
  printf(i != 0 ? " %d": "%d", A[i]);
  printf("\n%d\n", count);
  return 0;
}
