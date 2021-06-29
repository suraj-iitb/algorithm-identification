#include<stdio.h>
#define M 1000000
int main(){

  int i,n,q,l,r,mid,C=0,S[M],T[M];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  
  for(i=0;i<q;i++){
    l=0;
    r=n;
  while(l<r){
    mid=(l+r)/2;
    if(T[i]==S[mid]){
      C++;
      break;
    }
    if(T[i]>S[mid]){
      l=mid+1;
    }
    else if(T[i]<S[mid]){
      r=mid;
    }
    
  }

  
  }
  printf("%d\n",C);
  return 0;
}

