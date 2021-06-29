#include<stdio.h>
#define N 100000
#define Q 50000

int i,j;

int main(){
  int n,q,count=0,l,r,m;
  int S[N],T[Q];

  scanf("%d",&n);
  for(i=0 ; i<n ; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0 ; i<q ;i++){
    scanf("%d",&T[i]);
  }

 
  for(i=0 ; i<q ; i++){
    l=0;
    r=n;
    while(l<r){
      m=(l+r)/2;
      if(S[m]==T[i]){count++;break;}
      if(S[m]>T[i])r=m;
      if(S[m]<T[i])l=m+1;
    }
  } 
    printf("%d\n",count);
    
    return 0;
  }
