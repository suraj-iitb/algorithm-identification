#include<stdio.h>
#include<stdlib.h>
int main(){
  int count=0, i, N, n, x, *A;
  scanf("%d",&N);
  A = (int *)malloc(sizeof(int) * N);
  for(i=0; i<N; i++)
    scanf("%d",&A[i]);
  n = N;
  while(n){
    for(i=0; i<n-1; i++)
      if(A[i] > A[i+1]){
	x = A[i+1];
	A[i+1] = A[i];
	A[i] = x;
	count++;
      }
    n = n - 1;
  }
  for(i=0; i<N; i++){
    printf("%d",A[i]);
    i < N-1 ? printf(" "):printf("\n");
  }
    printf("%d\n",count);
  free(A);
  return 0;
}
