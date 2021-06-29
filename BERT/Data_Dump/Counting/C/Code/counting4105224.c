#include<stdio.h>
#include<stdlib.h>
#define MAX 2000000
#define VMAX 10001
int main(){
  int n, i, *A,*B, C[VMAX];
  scanf("%d", &n);
  A = (int*)malloc(sizeof(int)*MAX);
  for(i = 1; i < n+1; i++) scanf("%d", &A[i]);
  
  for(i = 0; i < VMAX; i++) C[i]=0;
  for(i = 1; i < n+1; i++) C[A[i]]++;
  for(i = 1; i < VMAX; i++) C[i] = C[i] + C[i-1];

  B = (int*)malloc(sizeof(int)*MAX);               
  for(i = n; i > 0; i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }

  for(i = 1; i < n+1; i++){
    if(i != 1) printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");

  free(A);
  free(B);
  return 0;
}

