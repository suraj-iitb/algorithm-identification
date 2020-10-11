#include <stdio.h>
int main()
{
  int A[100], N, n, i, j = 0, count = 0;

  scanf("%d",&N);
  for (i = 0; i < N; i++)
    scanf("%d",&A[i]);
  while (j < N-1){
    for (i = N-1; i >= j+1; i--){
      if (A[i] < A[i-1]){
	n = A[i];
	A[i] = A[i-1];
	A[i-1] = n;
	count++;
      }
    }
    j++;
  }
  for (i = 0; i < N; i++){
    printf("%d",A[i]);
    if (i != N-1)
      printf(" ");
  }
  printf("\n%d\n",count);
  
  return 0;
}

