#include <stdio.h>
int main(){

  int S[100000],T[50000];
  int i,n,q;
  int count = 0;
  int left,right,mid,num;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
  }

  //ここから計算
  //配列SからバイナリサーチでTの値を探す

  for(i = 0; i < q; i++){

    num = T[i];
    left = 0;
    right = n;
    while(left <= right){
      mid = (left + right) / 2;
      if(S[mid] == num){
	count++;
	break;
      }else if(S[mid] < num){
	left = mid + 1;
      }else{
	right = mid - 1;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

