#include <stdio.h>
#define M 1000000
int main(){

  int i,j,n,q,C=0,S[M],T[M];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(S[j]==T[i]){
	C++;
	break;
      }
    }
  }

  printf("%d\n",C);
  return 0;
}

