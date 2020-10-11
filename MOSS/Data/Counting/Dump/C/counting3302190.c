#include <stdio.h>
#include <stdlib.h>

void CountingSort(int *,int *,int);

int *C;
int n;

int main(){
  int k = 0,i;
  int *A;
  int *B;

  scanf("%d",&n);
  A = (int *)malloc(sizeof(int) * (n+1));
  B = (int *)malloc(sizeof(int) * (n+1));
  for(i = 1;i <= n;i++){
    scanf("%d",&A[i]);
    if(A[i] > k)
      k = A[i];
  }
  C = (int *)malloc(sizeof(int) * (k+1));

  CountingSort(A,B,k);

  for(i = 1;i <= n;i++){
    printf("%d",B[i]);
    if(i < n)
      printf(" ");
  }
  printf("\n");

  free(A);
  free(B);
  free(C);
  return 0;
}

void CountingSort(int *A,int *B,int k){
  int i;

  for(i = 0;i <= k;i++)
    C[i] = 0;

  for(i = 1;i <= n;i++)
    C[A[i]]++;

  for(i = 1;i <= k;i++)
    C[i] = C[i] + C[i-1];

  for(i = n;i >= 1;i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
}

