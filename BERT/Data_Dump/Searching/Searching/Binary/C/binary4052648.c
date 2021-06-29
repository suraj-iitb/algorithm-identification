#include <stdio.h>
#define N 100000
int main(){
  int i,j,n,q,S[N],T[N],cunt = 0,left = 0,right,mid;
  
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  for(j = 0;j < q;j++){
    scanf("%d",&T[j]);
  }
  right = i;
  for(j = 0;j < q;j++){
    while (left < right){
      mid = (left + right) / 2;
      if(S[mid] == T[j]){
	cunt++;
	break;
      }else if(T[j] < S[mid]){
	right = mid;
      }else{
	left = (mid + 1);
      }
    }
    left = 0;
    right = i;
  }
  printf("%d\n",cunt);
  return 0;
}

