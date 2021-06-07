#include <stdio.h>

int main(void){
  int S[100000],T[50000];
  int i,n,q,count=0;
  int mid=0,right=0,left=0;

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i = 0 ; i < q ; i++){
    scanf("%d",&T[i]);
  }
  for(i = 0 ; i < q ; i++){
    
    right = n;
    left = 0;
    
    while(right > left){
      
      mid = (right+left)/2;
      
      
      if(S[mid] == T[i]){
	count++;
	break;
      }
      else if(S[mid] < T[i]){
	left = mid+1;
      }
      else {
	right = mid;
      }
    }
  } 
  printf("%d\n",count);
  return 0;
}
