#include <stdio.h>
int main(){
  int A[100],i,j,k,l,N;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=1;i<=N-1;i++){
    for(k=0;k<N;k++){
      printf("%d",A[k]);
      if(k!=N-1)
	printf(" ");
    }
    printf("\n");
    l=A[i];
    j=i-1;
    while(j>=0&&A[j]>l){
      A[j+1]=A[j];
      j=j-1;
      A[j+1]=l;
    }
  }
  for(k=0;k<N;k++){
    printf("%d",A[k]);
    if(k!=N-1)
      printf(" ");
  }
  printf("\n");
  return 0;
} 
