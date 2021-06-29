#include<stdio.h>
#include<stdlib.h>

int main(){
  int N,i,j,v;
  int *A;
  scanf("%d",&N);
  if(N<1 && N>100){
    printf("Error");
    exit(1);
  }
  A=malloc(sizeof(int)*N);
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
  for(j=0; j<N; j++){
    printf("%d",A[j]);
    if(j!=N-1)printf(" ");
  }
  printf("\n");
  
  for(i=1; i<N; i++){
    v = A[i];
    j = i-1;
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(j=0; j<N; j++){
      printf("%d",A[j]);
      if(j!=N-1)printf(" ");
    }
    if(j=N-1)printf("\n");
  }

  return 0;
}

