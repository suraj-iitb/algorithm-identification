#include <stdio.h>

int main(){
  int A[100], i, j, N, minj, temp;
  int count = 0;
  scanf("%d", &N);
  for(i = 0; i < N; i++) scanf("%d", &A[i]);
  for(i = 0; i < N-1; i++){
    minj = i;
    for(j = i; j < N; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
    if(i != minj) count++;
  }
  printf("%d", A[0]);
  for(i = 1; i < N; i++) printf(" %d", A[i]);
  printf("\n");
  printf("%d\n", count);
  
  return 0;
}

