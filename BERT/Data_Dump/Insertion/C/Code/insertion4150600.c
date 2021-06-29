#include<stdio.h>
/* 配列の要素を順番に出力 */
void trace(int A[], int N)
{
  for (int i=0; i < N; i++ )
  {
    if(i> 0 )printf(" "); /* 隣接する要素の間に1つの空白を出力 */
    printf("%d", A[i]);
  }
  printf("\n");
}

/* 挿入ソート(0オリジン配列)*/
void insert(int A[], int N)
{
  int j, k;
  for (int i = 1; i < N; i++ )
  {
    k = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > k)
    {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = k;
    trace(A, N);
  }
}

int main()
{
  int N, j; 
  int A[100];

  scanf("%d", &N);
  for (int i = 0; i < N; i++ ) scanf("%d", &A[i]);
  trace(A, N);
  insert(A, N);

  return 0;

}

