#include <stdio.h>
#include<stdlib.h>

int main(){
  
  int A[1000];
  int i,j,key,N;
  
  scanf("%d",&N);
  
  if(N<1 || N>100) exit(1);
  
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0; i<N-1; i++)
    printf("%d ",A[i]);
  
  printf("%d",A[i]);
  printf("\n");
  
  for(j=1; j<N; j++){
    key = A[j];
    i=j-1;
    while((i>=0) && (A[i]>key)){
      A[i+1] = A[i];
      i=i-1;
    }
    A[i+1] = key;
    
    for(i=0; i<N-1; i++)
      printf("%d ",A[i]);
    
    printf("%d",A[i]);
    printf("\n");
  }
  return 0;
    }
  
