#include <stdio.h>
#include <stdlib.h>

int main() {
  int *A, i, j, n, v;

  scanf("%d", &n);

  A = (int *)malloc(n * sizeof(int));
  
  for(i = 0; i < n; i++) scanf("%d", &A[i]);

  for(j = 0; j < n; j++){
      printf("%d", A[j]);
      if(j == n-1) printf("\n");
      else printf(" ");
  }

  for(i = 1; i <= n-1; i++){
    v = A[i];
    j = i-1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    
    for(j = 0; j < n; j++){
      printf("%d", A[j]);
      if(j == n-1) printf("\n");
      else printf(" ");
    }
  }

  free(A);

  return 0;
}

