#include <stdio.h>

int selectionsort(int, int *);
int A[100];
int main()
{
  int i;
  int N,k;

  scanf("%d", &N);
  for (i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }
  k = selectionsort(N, A);
  printf("%d", A[0]);
  for (i = 1; i < N; i++){
    printf(" %d", A[i]);
  }
  printf("\n");
  printf("%d\n", k);

  return (0);
}
int selectionsort(int N, int *A)
{
  int i,j;
  int min;
  int num;
  int cnt;

  cnt = 0;
  for (i = 0; i < N; i++){
    min = i;
    for (j = i; j < N; j++){
      if (A[j] < A[min]){
	min = j;
      }
    }
    if (i != min){
      num = A[i];
      A[i] = A[min];
      A[min] = num;
      cnt++;
    }
  }
  return cnt;
}

