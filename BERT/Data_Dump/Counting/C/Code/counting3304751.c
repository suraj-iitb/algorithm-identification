#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int main(){
  int *A, *B;
  int C[MAX + 1];
  int n, i;
  
  scanf("%d",&n);
  A = malloc((n + 1) * sizeof(int));
  B = malloc((n + 1) * sizeof(int));

  for(i = 0; i <= MAX; i++){
    C[i] = 0;
  }
  for(i = 0; i < n; i++){
    scanf("%d",&A[i + 1]);
    C[A[i + 1]]++;
  }
  for(i = 0; i < MAX; i++){
    C[i + 1] = C[i] + C[i + 1];
  }
  for(i = n; i > 0; i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
  for(i = 1; i < n; i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);
  
  return 0;
}

