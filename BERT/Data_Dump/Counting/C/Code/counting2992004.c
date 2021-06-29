#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  unsigned short *A, *B;
  int C[VMAX+1];
  int n, i, j;
  int max=0;

  //長さの入力
  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  /* your code */
  //要素の入力
  for(i=1; i<=n; i++){
    scanf("%d",&A[i]);
    if(max<A[i]){
      max=A[i];
    }
  }
  //配列Cを初期化
  for(i=0; i<max; i++){
    C[i]=0;
  }
  //C[i]にiの出現数を記録する
  for(j=1; j<=n; j++){
    C[A[j]]++;
  }
  //C[i]にi以下の数の出現数を記録する
  for(i=1; i<=max; i++){
    C[i] = C[i] + C[i-1];
  }
  for(j=n; j>=1; j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

  for(i=1; i<=n; i++){
    printf("%d",B[i]);
    if(i!=n){
      printf(" ");
    }
  }
  printf("\n");
  return 0;
}

