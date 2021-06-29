#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int n;

void CountingSort(int *A, int *B,int k){
  int *C;
  C = (int *)malloc((k+1) * sizeof(int));
  for(int i = 0; i <= k; i++){
    C[i] = 0;
  }

  for(int i = 0; i < n; i++){
    C[A[i]]++;
  }

  for(int i = 1; i < k; i++){
    C[i] = C[i] + C[i-1];
  }

  for(int i = n-1; i > -1; i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
}

int main(){
  scanf("%d",&n);
  int *A, *B;
   A = (int *)malloc((n+1) * sizeof(int));
   B = (int *)malloc((n+1) * sizeof(int));
  for(int i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
  CountingSort(A,B,MAX);
  for(int i = 1; i <= n; i++){
    printf("%d",B[i]);
    if(i != n){
      printf(" ");
    }
  }
  printf("\n");
}

