#include<stdio.h>
#define N 1000
int main(){
  int i,j,n,q,S[10000],T[500],count=0;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(j=0; j<q; j++){
    scanf("%d",&T[j]);
  }
  for(i=0; i<q; i++){
    for(j=0; j<n; j++){
      if(S[j]==T[i]){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
}
