#include<stdio.h>

int main(){
  int A[100], tmp, N, i, j, v;
  
  scanf("%d", &N);
  for (i=0; i<N; i++) {
    scanf("%d", &A[i]);
  }

  for (i=1; i<N; i++) {
    
    for (j=0; j<N-1; j++) {
      printf("%d ", A[j]);
    }
    printf("%d\n", A[N-1]);
    
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
  }

  for (j=0; j<N-1; j++) {
    printf("%d ", A[j]);
  }
  printf("%d\n", A[N-1]);
  return 0;
}
