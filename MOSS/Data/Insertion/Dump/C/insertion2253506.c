#include<stdio.h>

int main() {
  int i, j, k, A[100], N, key;

  scanf("%d", &N);
  for(i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  
  for(i = 1; i < N; i++) {

    for(k = 0; k < N; k++) {
      if ( k > 0 ) printf(" ");
      printf("%d", A[k]);
    }
    printf("\n");
    
    key = A[i];
    j = i - 1;

    while(j >= 0 && A[j] > key) {
      A[j+1] = A[j];
      j--;
      A[j+1] = key;
    }
  }
  
  for(i = 0; i < N; i++) {
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");

  return 0;
}
