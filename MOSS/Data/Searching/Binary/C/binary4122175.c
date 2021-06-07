#include<stdio.h>

int main(){
  int S[100000],T[50000],n,q,i,l,m,r,count=0;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&T[i]);

    l=0;
    r=n;
    while(l<r){
    m=(l+r)/2;

    if(S[m]==T[i]){
      count++;
      break;
    }

    else if(S[m]<T[i])
      l=m+1;

    else
      r=m;
    }
  }

  printf("%d\n",count);

  return 0;
}
    

