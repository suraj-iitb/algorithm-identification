#include <stdio.h>

void swap(int *, int *);

int main(){
  int i,j,N,minj,count=0;
  int A[100];

  scanf("%d",&N);

  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0; i < N-1; i++){
    minj = i;
    for(j = i; j < N; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    if(A[i] != A[minj]){
      swap(&A[i],&A[minj]);
      count++;
    }
  }

  for(i = 0; i < N; i++){
    printf("%d",A[i]);
    if(i != N-1) printf(" ");
  }

  printf("\n%d\n",count);

  return 0;
}

void swap(int *x, int *y){
  int p;

  p = *x;
  *x = *y;
  *y = p;
}

