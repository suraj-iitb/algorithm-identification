#include<stdio.h>
int main(){
  int l,r,n,n2,i,S[1000000],T,mid,count;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&n2);
  for(i=0;i<n2;i++){
    scanf("%d",&T);
    l=0;
    r=n;
    while(l<r){
      mid=(l+r)/2;
      if(S[mid]==T){
	count++;
      break;
      }else if(S[mid]<T){
	l=mid+1;
      }else if(S[mid]>T){
	r=mid;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

