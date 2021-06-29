#include<stdio.h>
#define NMAX 100
#define AMAX 100

int main (){

  int i, j, N, A[AMAX], minj=1, flag, count = 0;

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

  /*選択ソート*/
  for(i = 0; i < N; i++){
    minj = i;
    for(j = i; j < N; j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
    if(i != minj) count++;
    flag = A[i];
    A[i] = A[minj];
    A[minj] = flag;
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

