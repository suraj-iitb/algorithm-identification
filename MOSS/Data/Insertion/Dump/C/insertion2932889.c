#include <stdio.h>
#include <stdlib.h>

int main (){
  int A[100],N,i,j,k,v;
  
  scanf("%d",&N);
  if(N > 100){
    printf("Size is too large.\n");
    exit(1);
  }
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
    if(A[i] > 1000){
      printf("Value is too large.\n");
      exit(2);
    }
  }
  
  for(k=0;k<N;k++){
    if(k == N-1)printf("%d",A[k]);
    else printf("%d ",A[k]);
  }
  printf("\n");
    
  for(i=1;i<N;i++){//Insertion Sort
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;   
    }
    A[j+1] = v;
    for(k=0;k<N;k++){
      if(k == N-1)printf("%d",A[k]);
      else printf("%d ",A[k]);
    }
    printf("\n");   
  }

  
  return 0;
}


