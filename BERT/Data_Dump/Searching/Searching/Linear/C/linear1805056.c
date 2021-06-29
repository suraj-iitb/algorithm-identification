#include<stdio.h>
int main(){

  int i,j,n,q,a,b;
  int S[10000],T[500],c=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
          }
      for(j=0;j<q;j++){
        for(i=0;i<n;i++){

          if(S[i]==T[j]){
            c++;
            break;
          }
        }}
      printf("%d\n",c);
    return 0;

  }
