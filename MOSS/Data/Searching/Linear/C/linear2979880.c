#include <stdio.h>

int main(){

  int S[10000],T[10000];

  int i,N1,N2,Q,l,k;

  scanf("%d",&N1);

  for(i=0;i<N1;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&N2);

  for(i=0;i<N2;i++){
    scanf("%d",&T[i]);
  }

  int count=0;

  
  for(l=0;l<N2;l++){
    for(k=0;k<N1;k++){
      
      if(S[k]==T[l]){
	count++;
	break;
      }
    }
  }

 
    printf("%d\n",count);

    return 0;

  }

