#include <stdio.h>

int main()
{
  int a, N, i ,j ,minj ,n = 0;
  int A[100] = {0};
  
  scanf("%d", &N);
  
  for (i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }
  
  for (i = 0; i < N; i++){
    minj = i;
    for (j = i; j < N; j++){
      if (A[j] < A[minj]){
        minj = j;
      }
    }
    if (i != minj){
      a = A[i];
      A[i] = A[minj];
      A[minj] = a;
      n++;
    }
  }
  
  
  for (i = 0; i < N - 1; i++){
    printf("%d ", A[i]);
  }
  
  
  printf("%d\n%d\n",A[i] ,n);
  
  
  return 0;
}
