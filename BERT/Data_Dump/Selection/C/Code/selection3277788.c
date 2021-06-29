#include <stdio.h>
#include <stdlib.h>
int main(){

  int N,i,j, *A,dummy,count = 0,minj;

  scanf("%d",&N);
  A = (int *)malloc(N * sizeof(int));
  for(j = 0;j < N;j++) {
    scanf("%d",&A[j]);
  }
  for(i = 0;i < N;i++){
    minj = i;
    for(j = i;j < N;j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
    if(i != minj) count++;
    dummy = A[minj];
    A[minj] = A[i];
    A[i] = dummy;
  }
  for(j = 0;j < N;j++){
    printf("%d",A[j]);
    if(j != N - 1) printf(" ");
  }
  printf("\n%d\n",count);

  
  return 0;
}

