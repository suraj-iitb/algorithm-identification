#include<stdio.h>
#include<stdlib.h>

int x;

void Counting_Sort(int *,int *,int);

main(){
  int *A,*B;
  int i,y;

  scanf("%d",&x);

  A = malloc(sizeof(int)*x);
  B = malloc(sizeof(int)*x);

  for(i=1;i<=x;i++){
    scanf("%d",&A[i]);
  }

  y = 0;

  for(i=1;i<=x;i++){
    if(y<A[i]){
      y = A[i];
    }
  }

  Counting_Sort(A,B,y);

  return 0;
}

void Counting_Sort(int *A,int * B,int k){
  int i,j,*C;

  C = malloc(sizeof(int)*x);

  for(i=0;i<=k;i++){
    C[i] = 0;
  }
  
  for(j=1;j<=x;j++){
    C[A[j]] = C[A[j]] + 1;
  }
  for(i=1;i<=k;i++){
    C[i] = C[i] + C[i-1];
  }
  for(j = x;j>0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]]-1;
  }
  for(i=1;i<=x;i++){
    printf("%d",B[i]);
    if(i<x){
      printf(" ");
    }
  }
  printf("\n");
}
