#include <stdio.h>
#include <stdlib.h>

int main(){
  int N,i,j,c = 0,ch;
  int *A;

  scanf("%d",&N);
  A = (int *)malloc(sizeof(int) * N);
  for(i = 0;i < N;i++)
    scanf("%d",&A[i]);

  for(i = 0;i < N-1;i++)
    for(j = N-1;j > i;j--)
      if(A[j] < A[j-1]){
	ch = A[j];
	A[j] = A[j-1];
	A[j-1] = ch;
	c++;
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

