#include<stdio.h>
#include<stdlib.h>
int main(){
  int count=0, i, j, N, min, x, *A;
  scanf("%d",&N);
  A = (int *)malloc(sizeof(int) * N);
  for(i=0; i<N; i++)
    scanf("%d",&A[i]);
  for(i=0; i<N-1; i++){
    min = i;
    for(j=i+1; j<N; j++){
      if(A[min] > A[j])
	min = j;
    }
    if(i != min){
      x = A[i];
      A[i] = A[min];
      A[min] = x;
      count++;
    }
  }
  for(i=0; i<N; i++){
    printf("%d",A[i]);
    i < N-1 ? printf(" "):printf("\n");
  }
  printf("%d\n",count);
  free(A);
  return 0;
}
