#include <stdio.h>

int main()
{
  int a , N, i, flag = 1, n = 0;
  int A[100] = {0};
  
  scanf("%d", &N);
  
  for (i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }
  
  while (flag) {
    flag = 0;
    for (i = N - 1; i > 0; i--) {
      if (A[i] < A[i-1]) {
        a = A[i];
        A[i] = A[i-1];
        A[i-1] = a;
        flag = 1;
        n++;
      }
    }
  }
  
  for (i = 0; i < N - 1; i++) {
    printf("%d ", A[i]);
  }
  printf("%d\n", A[i]);

  
  printf("%d\n", n);
  
  return 0;
}
