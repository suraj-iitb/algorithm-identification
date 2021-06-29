#include<stdio.h>
#include<stdlib.h>

int Max(int *, int);

int main(){
  int n, i, j, k;
  int *A, *B, *C;
  scanf("%d",&n);
  
  A = malloc(sizeof(int ) * n);
  B = malloc(sizeof(int ) * n);

  for(i = 1; i <= n; i++){
    scanf("%d",&A[i]);
  }

  k = Max(A, n);
  C = malloc(sizeof(int ) * (k+1));
  
  for(i = 0; i <= k; i++){
    C[i] = 0;
  }

  for(j = 1; j <= n; j++){
    C[A[j]]++;
      }

  for(i = 1; i <= k; i++){
    C[i] = C[i] + C[i - 1];
  }

  for(j = n; j >= 1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(j = 1; j <= n; j++){
    printf("%d",B[j]);
    if(j != n)printf(" ");
  }
  printf("\n");
  return 0;
}


int Max(int *A, int n){
  int k = A[1], i;
  for(i = 2; i <= n; i++){
    if(A[i] > k)k = A[i];
  }
  return k;
}

