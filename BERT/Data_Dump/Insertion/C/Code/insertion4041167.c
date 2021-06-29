#include <stdio.h>

int main()
{
  int N, //数列の長さを表す整数 N
      A[1000], key, i, j, k;


  /*入力*/
  scanf("%d", &N);
  if(N < 1 || 100 < N)
    printf("ERROR:1以上100以下の数列の長さを入力してください。");

  for(i = 0; i < N; i++)
    scanf("%d", &A[i]);



  /*挿入ソート*/
  for(i = 0; i < N; i++) //i が 1 から N-1 まで
  {
    key = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > key)
    {
      A[j + 1] = A[j];
      j--;
      A[j + 1] = key;
    }
    for(k = 0; k < N - 1; k++)
    {
      printf("%d ", A[k]);
    }
    printf("%d\n", A[k]);
  }
  return 0;
}
