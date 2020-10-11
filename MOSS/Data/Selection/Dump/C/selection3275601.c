#include<stdio.h>
#define NUM 100

int main(){
  int i,j,N,minj,temp;
  int change=0;
  int A[NUM];

  scanf("%d",&N);
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }

  for(i=0; i<N-1; i++){
    minj = i;
    for(j=i; j<=N-1; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    temp = A[minj];
    A[minj] = A[i];
    A[i] = temp;
    if(minj != i){
      change++;
    }
  }

  for(i=0; i<N; i++){
    printf("%d",A[i]);
    if(i < N-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",change);
  
  return 0;
}

