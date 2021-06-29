#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *,int,int);

int main(){
  int n,q,i,count=0,*S,*T,found;

  scanf("%d",&n);

  S=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  T=(int *)malloc(q*sizeof(int));
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    found=binarySearch(S,T[i], n);
  if(found==1)
    count++;
  }
  printf("%d\n",count);
  free(S);

  return 0;
}

int binarySearch(int *S,int x,int n){
  int left,right,mid;

  left=0;
  right=n;

  while(left<right){
    mid=(left+right)/2;
    if(S[mid]==x){
      return 1;
    }
    else if(S[mid]<x){
      left=mid+1;
    }else
      right=mid;
  }
  return 0;
}

