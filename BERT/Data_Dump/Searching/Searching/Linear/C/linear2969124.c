#include<stdio.h>
#include<stdlib.h>
int main(){

  int *S, *T,n,N,C,i,j;
  
  scanf("%d",&n);
  S = (int *)malloc(sizeof(int)*n);
  
  for(i=0; i<=n-1; i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&N);
  T = (int *)malloc(sizeof(int)*N);
  for(i=0; i<=N-1; i++){
    scanf("%d",&T[i]);
  }
  
  C=0;
  
  for(j=0; j<=N-1; j++){
    for(i=0; i<=n-1; i++){
      if(S[i]==T[j]){
	C++;
	break;
      }
    }
  }
  
  printf("%d\n",C);
  
  return 0;
}

