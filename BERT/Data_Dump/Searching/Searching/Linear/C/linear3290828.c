#include <stdio.h>

int main(){
  int i,j,n,q,count = 0;
  int S[10001],T[500];

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
  }

  for(i = 0; i < q; i++){
    j = 0;
    S[n] = T[i];
    
    while(S[j] != T[i]){
      j++;
    }

    if(j != n) count++;
  }

  printf("%d\n",count);

  return 0;
}

