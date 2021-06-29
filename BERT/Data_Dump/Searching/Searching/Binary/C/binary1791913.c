#include<stdio.h>

int main(){

  int S[100000],T[50000],count=0,n,q,i,j,left,mid,right,key;

  scanf("%d",&n);
  scanf("%d",&S[0]);
  for(i=1,j=1;j<n;i++){
    scanf("%d",&S[i]);
    if(S[i]==S[i-1])i--;
    j++;
  }
  n=i;
  scanf("%d",&q);
  for(i=0;i<q;i++) 
    scanf("%d",&T[i]);
   
  for(i=0;i<q;i++){
    key=T[i];
    left=0;
    right=n;
    while(left<right){
      mid=(left+right)/2;
      if(key==S[mid]){
	count++;
	break;
      }
      else if(key<S[mid])right=mid;
      else left=mid+1;
    }
  }

    printf("%d\n",count);

    return 0;
  }
