#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  unsigned int *A, *B;
  int C[VMAX+1];
  int n, i, j;
  int k = 0;

  scanf("%d", &n);

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);

  for(i = 1;i < n + 1; i++){
     scanf("%d",&A[i]);
     if(k < A[i]) k = A[i];
   }
  for(i =0;i < k;i++) C[i] = 0;
  for(j =1;j <= n; j++) C[A[j]]++;
  for(i = 1;i <= k;i++) C[i] = C[i] + C[i-1];
  for(j =n;j >=1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  for(i = 1;i <= n; i++){
     printf("%d",B[i]);
     if(i != n) printf(" ");
   }
  printf("\n");

  return 0;
}

