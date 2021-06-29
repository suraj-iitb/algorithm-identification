#include<stdio.h>
#define N 100000

int main(){
  int T[N],S[N],i,q,c=0,n,left,right,mid;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    left=0;
    right=n;
    while(left<right){
      mid=(left+right)/2;
      if(S[mid]==T[i]){
        c++;
	break;
      }
      else if(T[i]<S[mid])
	right=mid;
      else
	left=mid+1;
    } 
  }
  printf("%d\n",c);
  return 0;
}
