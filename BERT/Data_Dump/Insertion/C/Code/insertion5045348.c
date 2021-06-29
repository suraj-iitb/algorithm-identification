#include<stdio.h>
#define MAX 100/*最大の要素数*/
int main (){

  int N, A[MAX], i, j, k, v;

  /*入力する整数の数*/
  scanf("%d", &N);

  /*整数の入力*/
  for(i=0; i<N; i++)
    scanf("%d", &A[i]);
        
  if(N==1){
      printf("%d", A[0]);
      printf("\n");
  }

  /*挿入ソートと出力*/
  for(i=1; i<N; i++){
    /*ソート前の数列の表示*/
    if(i==1){
        for(k=0; k<N; k++){ 
            if(k!=N-1) printf("%d ", A[k]);
            else printf("%d", A[N-1]);
        }
        printf("\n");
    }
    /*挿入ソート*/
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    /*各計算ステップでの途中結果出力*/
    for(k=0; k<N; k++){
        if(k!=N-1) printf("%d ", A[k]);
        else printf("%d", A[N-1]);
    }
    printf("\n");
  }
  return 0;
}
