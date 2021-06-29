#include <stdio.h>

int main(){

  int S[10000],T[500];
  int i,j,n,q;
  int count = 0;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
  }

  //ここから計算
  //Tの最初の要素とSの要素を比較し同じものだけカウント

  for(i = 0; i < q; i++){
    for(j = 0; j < n; j++){
      if(T[i] == S[j]){
	count++;
	break;
      }
    }
  }
  
  printf("%d\n",count);
  return 0;
}

