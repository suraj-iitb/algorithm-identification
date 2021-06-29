#include <stdio.h>

int main(){
  int i,j,S[10000],T[500],n,q,C=0;
  
  scanf("%d",&n);
  for(j=0;j<n;j++){
    scanf("%d",&S[j]);
  }
  
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }

  for(j=0;j<q;j++){
    i = 0;
    S[n] =  T[j];
    while(T[j] != S[i]){
      i++;
    }
    if(i < n) C++;
  }

  printf("%d\n",C);

  return 0;
}  

