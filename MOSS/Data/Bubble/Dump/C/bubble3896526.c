#include<stdio.h>


void swap(int *x, int *y)
{
  int tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;
 
}


int bubbleSort(int *A, int N)
{
  int count = 0;

  int flag = 1; // 逆の隣接要素が存在するかどうか
  while(flag){
    flag = 0;
    int j = N-1;
    while(j >= 1){
      if (A[j] < A[j-1]) {
        swap(&A[j], &A[j-1]);

        flag = 1;
        count++;
      }
      j--;
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

  count = bubbleSort(A, N);

  for (int i = 0; i< N-1; i++)
    printf("%d ", A[i]);
  printf("%d\n", A[N-1]);

  printf("%d\n", count);

  return 0;
}

  

