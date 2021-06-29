#include <stdio.h>

int main(){
  int n,q,s[100000],t[50000],i,left,right,mid,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&t[i]);

  for(i=0;i<q;i++){
    left=0;
    right=n;
    mid=(left+right)/2;
    while(left<right){
      if(t[i]>s[mid]) left=mid+1;
      else if(t[i]<s[mid]) right=mid;
      else{
	count++;
	break;
      }
      mid=(left+right)/2;
    }
  }
  printf("%d\n",count);
  return 0;
}

