#include<stdio.h>
#include<stdlib.h>

int main(){
  int *A;
  int N,i,j,a,minj,count=0;
  scanf("%d",&N);
  A = (int *)malloc(N * sizeof(int));
  for(i = 0;i < N;i++){
    scanf("%d",&A[i]);
  }
  for(i = 0;i <= N-1;i++){
    minj = i;
    for(j = i;j <= N-1;j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    if(A[i] != A[minj])count++;
    a = A[minj];
    A[minj] = A[i];
    A[i] = a;
  }
  for(i = 0;i < N;i++){
    printf("%d",A[i]);
    if(i != N-1)printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}

