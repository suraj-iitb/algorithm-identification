#include <stdio.h>
#include <stdlib.h>

int main(){
  int N,i,j,c = 0,minj,ch;
  int *A;

  scanf("%d",&N);
  A = (int *)malloc(sizeof(int) * N);
  for(i = 0;i < N;i++)
    scanf("%d",&A[i]);

  for(i = 0;i < N-1;i++){
    minj = i;
    for(j = i+1;j < N;j++){
      if(A[j] < A[minj])
	minj = j;
    }
    if(A[minj] < A[i]){
    ch= A[i];
    A[i] = A[minj];
    A[minj] = ch;
    c++;
    }
  }

  for(i = 0;i < N;i++){
    printf("%d",A[i]);
    if(i < N-1)
      printf(" ");
  }
  printf("\n%d\n",c);

  free(A);
  return 0;
}

