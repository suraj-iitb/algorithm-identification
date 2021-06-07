#include<stdio.h>
int main(){

  int n,q,i,j,C=0;
  int l,r,m;
  int S[100000],T[50000];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
    for(j=0;j<q;j++){
      scanf("%d",&T[j]);
    }

    for(j=0;j<q;j++){
      l=0;
      r=n;
      while(l<r){
        m=(l+r)/2;
        if(S[m]==T[j]){
          C++;
          break;
        }
          if(T[j]<S[m]){
            r=m;
          }
          if(T[j]>S[m]){
            l=m+1;
          }

    }
}
        printf("%d\n",C);
return 0;
}
