#include<stdio.h>

int main(){
  int i, j, n, q;
  int count=0;
  int S[10001], T[501];
  
  //Sのデータの入力
  scanf("%d", &n);
  for( i=0 ; i<n ; i++){
    scanf("%d", &S[i]);
  }
  //Tのデータの入力
  scanf("%d", &q);
  for( i=0 ; i<q ; i++){
    scanf("%d", &T[i]);
  }
  //探索開始へへへ
  for( i=0 ; i<q ; i++){
    S[n] = T[i];//番兵作成なう
    j=0;
    while( S[j]!=T[i] ){
      j++;
    }
    if( j<n ){
      count++;
    }
  }
  printf("%d\n",count);
  return 0;
}

