#include <stdio.h>
#include <stdlib.h>

int main (){
  int N;
  scanf("%d", &N);
  int *A = (int *)malloc(sizeof(int) * N);
  
  for (int i = 0; i < N; i++){
    scanf(" %d", &A[i]);
    if (i == N-1){
      printf("%d\n", A[i]);
    }else {
      printf("%d ", A[i]);
    }
  }

  for (int i = 1; i < N; i++){
    int v = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;

    for (int k = 0; k < N; k++){
      if (k == N-1){
	printf("%d\n", A[k]);
      } else {
	printf("%d ", A[k]);
      }
    }
    
  }
  
  free(A);
  
  return 0;
}

