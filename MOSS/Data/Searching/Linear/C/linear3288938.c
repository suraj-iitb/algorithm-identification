#include<stdio.h>

    
int main(){
  int n,S[10000],q,T[10000];
  int k;
  int C = 0,i,j;
  scanf("%d",&n);
  for(k = 0;k < n;k++) scanf("%d",&S[k]);
  scanf("%d",&q);
  for(k = 0;k < q;k++) scanf("%d",&T[k]);
  
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(S[j] == T[i]){
	C++;
	break;
      }
    }
  }
  printf("%d\n",C);
  return 0;
}

