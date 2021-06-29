#include <stdio.h>
#include <stdlib.h>

#define NMAX 2000001

void CountingSort (int *,int *,int);
int n;

int main (void)
{
  int *a,*b,i,k,result;
  
  //input
  scanf ("%d",&n);

  //ヒープメモリ確保
  a = malloc(sizeof(int) * NMAX);
  b = malloc(sizeof(int) * NMAX);

  //input
  for (i = 1 ; i <= n ; i++){
    scanf ("%d",&a[i]);
  }

  //CountingSort関数で用いるC[i]の要素数の決定
  k = 0;
  for (i = 1 ; i <= n ; i++){
    if (k < a[i])
      k = a[i];
    }

  //CountingSort関数へ移動
    CountingSort (a,b,k);

  //output
  for (i = 1 ; i <= n ; i++){
    printf ("%d",b[i]);
    if (i < n)
      printf (" ");
    else
      printf ("\n");
  }

  //ヒープメモリ解放
  free(a);
  free(b);

  return 0;
}

void CountingSort (int *a,int *b,int k)
{
  int i,j,*c;

  //ヒープメモリ確保
  c = malloc(sizeof(int) * k);

  for (i = 0 ; i <= k ; i++){
    c[i] = 0;
  }

  //C[i] に i の出現数を記録する
  for (j = 1 ; j <= n ; j++){
    c[a[j]]++;
  }

  //C[i] に i 以下の数の出現数を記録する
  for (i = 1 ; i <= k ; i++){
    c[i] = c[i] + c[i-1];
  }

  for (j = n ; j >= 1 ; j--){
    b[c[a[j]]] = a[j];
    c[a[j]]--;
  }

  //ヒープメモリ解放
  free(c);

  return;
}
