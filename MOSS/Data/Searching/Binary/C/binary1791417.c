#include <stdio.h>
#define N 100000
#define Q 50000

int main(){

  int i,j,q,left,right,count=0,n,mid;
  int T[Q],S[N];
 
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(j=0;j<q;j++) scanf("%d",&T[j]);
  
  for(j=0;j<q;j++){
    left=0;
    right=n;
    while(left < right){
      mid = (left + right) / 2;
      
      if(S[mid] == T[j]){
	count++;
	break;
      }
      else if(T[j] < S[mid]) right = mid; 
      else left = mid + 1;
    }
  }
  
  printf("%d\n",count);
  return 0;
}
