#include <stdio.h>

int main()
{
  int A[100], N, a, count=0, i, j;

  scanf("%d",&N);
  for(j = 0 ; j < N ; j++){
    scanf("%d",&A[j]);
  }
  
  for(i = 0 ; i < N-1 ; i++){
    for(j = N-1 ; j > i ; j--){
      if(A[j] < A[j-1]){
	a = A[j];
	A[j] = A[j-1];
	A[j-1] = a;
	count++;
      }
    }
  }

  for(j = 0 ; j < N-1 ; j++){
    printf("%d ",A[j]);
  }
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
  return 0;
}
