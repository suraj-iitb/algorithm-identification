#include<stdio.h>
#include<stdlib.h>

#define MAX 2000001

int B[10001];
 
int main(){
 
  unsigned short *A,*C;
  int i,sumdata;

 
  scanf("%d",&sumdata);

  A = malloc(sizeof(short)*sumdata+1);
  C = malloc(sizeof(short)*sumdata +1);


  for(i = 0; i < sumdata; i++){
 
    scanf("%d",&A[i]);
 
    B[A[i]] = B[A[i]] + 1;
 
  }
 
 
  for(i =1; i <= 10000; i++){
 
    B[i] = B[i] + B[i -1];
 
  }
 
  /* for(i = 0; i < sumdata; i++){
 
    printf("%d ",B[i]);
 
    }*/
 
  for(i = sumdata -1; i >= 0 ; i--){
 
    /*  printf("%d ", B[A[i]]);*/
 
    C[B[A[i]]] = A[i];
 
    B[A[i]] = B[A[i]] -1;
 
  }
 
 
  for(i = 1; i < sumdata; i++){
 
    printf("%d ",C[i]);
 
  }
 
 
  printf("%d\n",C[sumdata]);
 
 
 
  return 0;
 
}

 

 
