#include <stdio.h>
#include <stdlib.h>


int main()
{
  int n,  q ,C=0,i,j,left,right,mid;

  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }


  for(i=0;i<q;i++){
    left=0;
    right=n;
    while(left<right){
      
      mid=(left+right)/2;
      if(T[i]==S[mid]){
	C++;
	break;
      }
      
      else if(T[i]<S[mid]){
	right=mid;
      }
      
      else{
      left=mid+1;
      }
    }
  }

   printf("%d\n",C);

  return 0;
}
