#include<stdio.h>
#include<stdlib.h>
int main(){
  int i,j,nS,nT,q,count;
  int S[10000];
  scanf("%d",&nS);
  for(i=0;i<nS;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&nT);
  count = 0;
  for(i=0;i<nT;i++){
    scanf("%d",&q);
    j = 0;
    while(S[j] != q && j<nS){
      j++;
    }
    if( S[j] == q){
      count++;
    }
  }
  printf("%d\n",count);
  return 0;
}
