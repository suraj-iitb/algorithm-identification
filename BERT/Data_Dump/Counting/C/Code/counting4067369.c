#include<stdio.h>
#include<stdlib.h>

#define N 2000000
#define M 10000

void CountingSort(unsigned short*,unsigned short*);

int C[M+1],n;

int main(){
  unsigned short *A,*B;
  int i,j;

  scanf("%d",&n);

  A=malloc(sizeof(short)*n-1);
  B=malloc(sizeof(short)*n-1);
  
  for(i=0;i<n;i++){
    scanf(" %d",&A[i]);
  }

  CountingSort(A,B);

  
  printf("%d",B[1]);
  for(i=2;i<n+1;i++){
    printf(" %d",B[i]);
  }
  printf("\n");


  return 0;
}

void CountingSort(unsigned short *A,unsigned short *B){
  int i,j;

  for(i=0;i<M+1;i++){
    C[i]=0;
  }

  for(j=0;j<n;j++){
    C[A[j]]++;
  }

  for(i=1;i<M+1;i++){
    C[i]=C[i]+C[i-1];
  }

  for(j=n-1;j>=0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

  
  return;
}
  

