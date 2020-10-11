#include<stdio.h>
#include<stdlib.h>
#define k 10001
void CountingSort(int *, int *, int);
main(){
  int n, i;
  int *A, *B;
  scanf("%d", &n);
  A = (int *)malloc(sizeof(int)*n);
  if(A == NULL) exit(1);
  B = (int *)malloc(sizeof(int)*n);
  if(B == NULL) exit(2);
  
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  CountingSort(A, B, n);
  for(i = 0; i < n; i++){
    if(i == 0) printf("%d",  B[i]);
    else       printf(" %d", B[i]);
  }
  printf("\n");
  free(A);
  free(B);
  return 0;
}

void CountingSort(int *A, int *B,int n){
  int i;
  int C[k];
  for(i = 0; i < k; i++){
    C[i] = 0;
  }
  for(i = 0; i < n; i++){
    C[A[i]]++;
  }
  for(i = 1; i < k; i++){
    C[i] = C[i]+C[i-1];
  }
  for(i = n; i >= 1; i--){
    B[ C[A[i-1]]-1 ] = A[i-1];
    C[A[i-1]]--;
  }
}
