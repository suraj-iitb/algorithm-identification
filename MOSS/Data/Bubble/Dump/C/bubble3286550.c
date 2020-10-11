#include <stdio.h>
#include <stdlib.h>
int main(){
  int N,j,i=0,*A,num,k=0;

  scanf("%d",&N);
  A = (int *)malloc(N * sizeof(int));

  for(j = 0 ; j < N ; j++) scanf("%d",&A[j]);

  for(i = 0 ; i < N-1 ; i++){
    for(j = N-1 ; j >= i+1 ; j--){ 
      if(A[j] < A[j-1]){
	num = A[j];
	A[j] = A[j-1];
	A[j-1] = num;
	k++; }
    }
  }

  for(j = 0 ; j < N-1 ; j++) printf("%d ",A[j]);
  printf("%d\n",A[j]);
  printf("%d\n",k);
  free(A);

  return 0;
}

