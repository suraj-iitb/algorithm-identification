#include <stdio.h>
#include <stdlib.h>

int main(void){
  int i,n,q,mid,left,right,cnt = 0;
  int S[100000],T[50000];

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&T[i]);
  }


  for(i = 0;i < q;i++){
    left = 0;
    right = n;
    while(left < right){
      
      mid = (left + right) / 2;
      
      if(S[mid] == T[i]){
	cnt++;
	break;
      }
      else if(S[mid] > T[i]){
	right = mid;
	
      }else {
	left = mid + 1;
      }
    }
  }

  printf("%d\n",cnt);     

  return 0;
}

