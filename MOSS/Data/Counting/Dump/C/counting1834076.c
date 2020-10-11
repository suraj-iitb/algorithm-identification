#include<stdio.h>
#include<stdlib.h>

#define MAX 10000

int main(){
  int n, *A, i, *B, C[MAX];

  scanf("%d",&n);

  A = (int *)malloc(sizeof(int) * n + 1);
  B = (int *)malloc(sizeof(int) * n + 1);

  for(i = 1; i < n + 1; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0; i < MAX; i++) C[i] = 0;

  for(i = 0; i < n; i++) C[A[i + 1]]++;

  for(i = 0; i < MAX; i++) C[i] = C[i] + C[i-1];

  for(i = n; i > 0; i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }

  for(i = 1; i < n; i++) printf("%d ",B[i]);
  printf("%d\n", B[n]);

  return 0;
}
