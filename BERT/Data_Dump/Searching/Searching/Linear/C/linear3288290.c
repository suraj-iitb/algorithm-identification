#include<stdio.h>

int main(){
  int i,j,C=0,n,q;
  int S[10000],T[10000];

  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i = 0; i < q; i++) scanf("%d",&T[i]);

  for(i = 0; i < q; i++){
    for(j = 0; j < n; j++){
      if(S[j] == T[i]){
	C += 1;
	break;
      }
    }
  }
  printf("%d\n",C);
}

