#include<stdio.h>
#include<stdlib.h>
int main(){

  int i, j, N, minj, K,count=0;
  int *A;
  scanf("%d",&N);
  A = (int *)malloc(sizeof(int)*N);

  for(i=0; i<=N-1; i++){
    scanf("%d",&A[i]);
  }

  for(i=0; i<=N-1; i++){
    minj = i;
      for(j=i; j<=N-1; j++){
        if (A[j] < A[minj])
          minj = j;
      }
      if(i != minj) count++;
    K = A[i];
    A[i] = A[minj];
    A[minj] = K;
      }
  printf("%d",A[0]);
  for(i=1;i<=N-1;i++){
  printf(" %d",A[i]);
  }
  printf("\n%d\n",count);
  return 0;
}
