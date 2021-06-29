#include<stdio.h>

int main(){
  int i,j,C=0,n,q,left  ,right,mid;
  int S[100000],T[50000];

  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i = 0; i < q; i++) scanf("%d",&T[i]);

 
  for( i = 0; i < q;i++){
    right = n; left = 0;
    while(left < right ){
      mid = (left + right)/2;
    if(S[mid] == T[i]){
      C++;
      break;
    }
    else if(T[i] < S[mid]) right = mid;
    else left = mid + 1;
      }
  }
  printf("%d\n",C);
  return 0;
}

