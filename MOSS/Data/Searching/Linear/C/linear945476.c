#include <stdio.h>
#define N 10000
#define Q 500

int main(){
  
  int n,q,i,j,S[N],T[Q],C=0;
  
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(j = 0; j < q; j++){
    scanf("%d",&T[j]);
  }
  
  for(j = 0; j < q; j++){    
    for(i = 0; i < n; i++){
      if(S[i] == T[j]){
	C++;
	break;
      }
    }
  }
  printf("%d\n",C);
  return 0; 
}
