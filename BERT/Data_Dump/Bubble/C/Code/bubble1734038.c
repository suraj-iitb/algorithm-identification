#include <stdio.h>
int main()
{
  int i,j,x,N,A[100],count=0;

  scanf("%d",&N);
  for(i = 0; i < N; i++) {
  scanf("%d",&A[i]);
  }

  for(i = 0; i < N-1; i++) {
    for(j = N-1; j > i; j--) {
      if(A[j] < A[j-1]) {
	x = A[j];
	A[j] = A[j-1];
	A[j-1] = x;
	count++;
      }
    }
  }

  for(i = 0; i < N; i++) {
    printf("%d",A[i]);
    if(N-1 != i) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
 
