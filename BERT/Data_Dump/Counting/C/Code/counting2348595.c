#include<stdio.h>
#include<stdlib.h>
#define N 2000001
#define G 10000

int main(){

  unsigned short *A,*B;
  int i,j,x,C[G+1];

  scanf("%d",&x);
  A = malloc(sizeof(short) * x+1);
  B = malloc(sizeof(short) * x+1);
  
  
  for(i=0;i<=G;i++){
    C[i]=0;
  }
  
  for(j=0;j<x;j++){
    scanf("%hu",&A[j+1]);
    C[A[j+1]]++;
  }
  
  for(i=1;i<=G;i++){
    C[i] = C[i] + C[i-1];
  }
  
  for(j =1;j<=x;j++){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  
  
  
  for(i=1;i<=x;i++){
    if(i>1)  printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  
  return 0;
}
