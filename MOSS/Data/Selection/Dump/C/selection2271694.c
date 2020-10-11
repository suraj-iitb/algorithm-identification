#include <stdio.h>

int main()
{
  int N, i, j, A[100], minj, a, c = 0;
  

  scanf("%d", &N);
  for(i = 0; i < N; i++) scanf("%d", &A[i]);

  for(i = 0; i <= N - 1; i++){
    minj = i;
    for(j = i; j <= N - 1; j++){
      if(A[j] < A[minj]) {
	minj = j;
      }
    }
    a = A[i];
    A[i] = A[minj];
    A[minj] = a;
    if(i != minj)   c++;
  }
  
  for(i = 0; i < N; i++){
    printf("%d", A[i]);
    if(i != N - 1) printf(" ");
  }
  printf("\n%d\n", c);
  return 0;
}
