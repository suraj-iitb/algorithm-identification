#include<stdio.h>

int main(){
  int n,q,i,key,j,k=0;
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(j=0;j<q;j++){
    i=0;
    while(1){
      if(T[j]==S[i]){
        k++;
        break;
      }
      if(i==n){
        break;
      }
      i++;
    }
  }
  printf("%d\n",k);
  return 0;
}

