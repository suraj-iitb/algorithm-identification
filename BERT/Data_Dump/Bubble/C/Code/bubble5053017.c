#include<stdio.h>
#define NMAX 100
#define AMAX 100

int main (){

  int j, N, A[AMAX], flag=1, count = 0;

  /*数列の長さの入力*/
  scanf("%d", &N);
  if(N < 0 || N > NMAX){
    printf("入力できる整数は0個から%d個までです。\n", NMAX);
    return 0;
  }

  /*整数の入力*/
  for(j = 0; j < N; j++){
    scanf("%d", &A[j]);
    if(A[j] < 0 || A[j] > AMAX){
      printf("入力できる整数は0から%dまでです。\n", AMAX);
      return 0;
    }
  }

  /*バブルソート*/
  while(flag){
    flag = 0;
    for(j = N-1; j > 0; j--){
      if(A[j] < A[j - 1]){
        flag = A[j];
        A[j] = A[j - 1];
        A[j - 1] = flag;
        flag = 1;
        count++; 
      }
    }
  }

  /*ソート後の数列の出力*/
  for(j = 0; j < N; j++){
    if(j != N-1) printf("%d ", A[j]);
    else printf("%d", A[j]);
  }
  
  printf("\n");

  /*合計の交換回数の出力*/
  printf("%d\n", count);

  return 0;
}

