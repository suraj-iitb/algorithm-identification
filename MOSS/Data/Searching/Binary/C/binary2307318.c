#include <stdio.h>
int main(){
  int i,n,q,c=0,left,right,mid;

  scanf("%d",&n);

  int S[n];
  for(i=0;i<n;i++) scanf("%d",&S[i]);

  scanf("%d",&q);

  int T[q];
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);

    left=0;
    right=n;

    while(left<right){
      mid=(left+right)/2;

      if(T[i]>S[mid]) left=mid+1;
      else if(T[i]<S[mid]) right=mid;
      
      else{
	c++;
	break;
      }
    }
  }

  printf("%d\n",c);

  return 0;
}
