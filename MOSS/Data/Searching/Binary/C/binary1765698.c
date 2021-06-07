#include<stdio.h>
int main(){
  int i,nForS,nForT,q,left,right,mid,count;
  int S[100000];
  scanf("%d",&nForS);
  for(i=0;i<nForS;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&nForT);
  count = 0;
  for(i=0;i<nForT;i++){
    scanf("%d",&q);
    left = 0;
    right = nForS;
    while(left < right){
      mid = (left+right)/2;
      if( S[mid] == q ){
	count++;
	break;
      }
      if( q < S[mid]){
	right = mid;
      }
      else if( S[mid] < q){
	left = mid + 1;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}
