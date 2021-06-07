#include <stdio.h>

int Binary(int[],int,int);

int main(){
  int S[100000],T,n,q,i,j,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T);
    if(Binary(S,T,n)==0)count=count+1;
  }

  printf("%d\n",count);
  return 0;
}

int Binary(int S[],int T,int n){
  int l=0;
  int r=n;
  int m;

  while(l<r){
    m = (l+r)/2;

    if(T==S[m])return 0;
    if(T > S[m])l = m+1;
    else if(T < S[m])r = m;
  }

  return 1;
}

