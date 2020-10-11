#include <stdio.h>
#include <stdlib.h>
int main(){

  int N;
  int A[100];
  int i, j, key, temp1, temp2;

  scanf("%d",&N);
 
  for(i=0; i<N; i++){
    scanf("%d", &A[i]);
  }
  
  for(i=0; i<N-1; i++){
      printf("%d ", A[i]);
  }
  printf("%d", A[N-1]);
    printf("\n");
  
  for(j=1; j<=N-1; j++){
    key = A[j];
    i=j-1;
    while(i>=0 && A[i]>key){
      temp1=A[i]; temp2=A[i+1];
      A[i+1]=temp1; A[i]=temp2;
      i=i-1;
      
    }
    for(i=0; i<N-1; i++){
      printf("%d ", A[i]);
    }
    printf("%d", A[N-1]);
    printf("\n");

    
    A[i+1]=key;
  }
  
  return 0;
}

