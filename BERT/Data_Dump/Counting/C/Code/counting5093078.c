#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  unsigned short *A, *B;
  int C[VMAX+1];
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  /* your code */
  int k;
  k = VMAX;
  for(i = 0; i < k; i++){
    C[i] = 0;
  }

  for(j = 0; j < n; j++){
    scanf("%hu", &A[j + 1]);
    C[A[j+1]]++;
  }

  for(i = 1; i <= k; i++){
    C[i] =C[i] + C[i-1];
  }

  for(j = 1; j <= n; j++){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i = 1; i <= n; i++){
    if(i < n){
      printf("%d ", B[i]);
    }else{
      printf("%d\n", B[i]);
    }
  }

  return 0;
}
