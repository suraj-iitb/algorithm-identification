//2020 1.26 計数ソート

#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main()
{
  unsigned short *A, *B;  //マイナスの値をとらないshort型の時にunsignedを使う
  int C[VMAX+1];

  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=0;i<=VMAX;i++) C[i]=0;   //使用されるであろう10000個の配列要素を0に初期化しておく

  for(i=0;i<n;i++)
  {
      scanf("%d",&A[i+1]); //1オリジンの配列に入力
  }

  for(i=0;i<n;i++)
  {
    C[A[i+1]] = C[A[i+1]] + 1;  //Cの配列要素A[i+1]にプラス１ずつしていく
  }

  for(i=1;i<=VMAX;i++)
  {
      C[i] = C[i] + C[i-1];  //Cの配列要素を足しあわしていく
  }

  for(i=1;i<=n;i++)
  {
      B[C[A[i]]] = A[i]; 
      C[A[i]] = C[A[i]] - 1;
  }

  for(i=1;i<=n;i++)
  {   
      if(i > 1) printf(" ");
      printf("%d",B[i]);
  }
  printf("\n"); 

  return 0;
}
