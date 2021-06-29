#include <stdio.h>
#include <stdlib.h>

int main(){
  int A[100];
  int i, j, minj, n, swap = 0, tmp;

  scanf("%d", &n);
  if(n < 1 && 100 < n) exit(1);

  for(i = 0; i <= n -1; i++){
    scanf("%d", &A[i]);
  }

  for(i = 0; i <= n - 1; i++){
    minj = i;
    for(j = i; j <= n - 1; j++){
      if(A[j] < A[minj])
        minj = j;
    }
    if(A[minj] != A[i]){
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
    swap++;
    }
  }
  for(i = 0; i <= n - 1; i++){
    printf("%d", A[i]);
    if(i == n - 1)
      printf("\n");
    else
      printf(" ");
  }
  printf("%d\n", swap);

  return 0;
}

