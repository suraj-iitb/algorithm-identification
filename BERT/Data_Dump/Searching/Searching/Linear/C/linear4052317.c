#include <stdio.h>

int main(){
  int i,j,n,q,S[10000],T[10000],sum = 0;

  
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }
  
  
  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
  }
  
  
  for(i = 0; i < q; i++){
    for(j = 0; j < n; j++){
      if(T[i] == S[j]){
	sum++;
	break;
      }
    }
  }
  
  printf("%d\n",sum);

  return 0;
}

