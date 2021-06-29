#include<stdio.h>

int main(void){

  int i,n,q,left,right,mid,count=0;
  int S[100000],T;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&T);
    
    left=0;
    right=n;
    
    while(left < right){
      mid=(left + right)/2;
      if(S[mid] == T){
	count++;
	break;
      }
      else if(S[mid] > T) right=mid;
      else left=mid+1;
    }
  }
  
  
  
  printf("%d\n",count);
  
  return 0;
}
