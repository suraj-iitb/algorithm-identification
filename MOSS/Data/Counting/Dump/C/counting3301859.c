#include<stdio.h>
#include<stdlib.h>
#define N 2e6
#define K 10000

void CountingSort(int*, int*, int);

void CountingSort(int *A, int *B, int n){

  int i;

  int *C=(int*)malloc(sizeof(int)*K);

  for(i=0;i<=K;i++) C[i]=0;

  for(i=1;i<=n;i++) C[A[i]]++;

  for(i=1;i<=K;i++) C[i]+=C[i-1];

  for(i=n;i>0;i--){

    B[C[A[i]]]=A[i];

    C[A[i]]--;

  }free(C);

  return;

}

int main(){

  int i, n;

  scanf("%d", &n);

  int *A=(int*)malloc(sizeof(int)*N);

  int *B=(int*)malloc(sizeof(int)*N);

  for(i=1;i<=n;i++) scanf("%d", &A[i]);

  CountingSort(A, B, n);

  printf("%d", B[1]);

  for(i=2;i<=n;i++) printf(" %d", B[i]);

  printf("\n");

  free(A);
  free(B);

  return 0;

}

