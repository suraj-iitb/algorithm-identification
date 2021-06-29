#include <stdio.h>

int main()
{
  int N, A[100], i, f, a, c = 0, j = 0;

  scanf("%d", &N);
  for(i = 0; i < N; i++) scanf("%d", &A[i]);

  f = 1;
  while(f){
    f = 0;
    for(i = N - 1; i >= j + 1; i--){
      if(A[i] < A [i - 1]){
	a = A[i];
	A[i] = A[i - 1];
	A[i - 1] = a;
	c++;
	f = 1;
      }
    }
    j++;
  }

  for(i = 0; i < N; i++){
    printf("%d", A[i]);
    if(i != N - 1) printf(" ");
  }
  printf("\n%d\n", c);

  return 0;
}
