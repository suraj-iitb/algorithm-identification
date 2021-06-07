#include<stdio.h>
#include<stdlib.h>

int BS(int *,int,int);

int main(){
  int i,j,n,q,C=0;
  int *S,*T;
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
    C+=BS(S,n,T[i]);
  }
  printf("%d\n",C);
  return 0;
}

int BS(int *P,int n,int k){
  int r=n,l=0,t;
  while(l<r){
    t=(r+l)/2;
    if(k==P[t]){
      return 1;
    }
    if(k>P[t]){
      l=t+1;
    }
    else if(k<P[t]){
      r=t;
    }
  }
  return 0;
}

