#include<stdio.h>


void swap(int *x, int *y)
{
  int tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;
 
}


int selectionSort(int *A, int N) // N個の要素を含む0-オリジンの配列A
{
  int minj, tmp;
  int count = 0;
  
  for(int i=0; i<N; i++){
    minj = i;
    for(int j=i; j<N; j++){
      if (A[j] < A[minj])
        minj = j;
    }
    if (i != minj) {
      swap(&A[i], &A[minj]);
      count++;
    }
  }

  return count;
}

int main(void)
{
  int A[100], N, i;
  int count;
  
  scanf("%d",&N);
  for(i=0;i<N;i++) {
    scanf("%d", &A[i]);//配列読み込み
  }    

  count = selectionSort(A, N);

  for (int i = 0; i< N-1; i++)
    printf("%d ", A[i]);
  printf("%d\n", A[N-1]);

  printf("%d\n", count);

  return 0;
}

  

