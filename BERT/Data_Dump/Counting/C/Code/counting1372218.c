#include <stdio.h>
#include <stdlib.h>
#define N 2000000
int n;
void Counting_Sort(int *A, int *B, int k){
  int i, j, C[10001];
  for(i = 0; i <= k; i++) C[i] = 0;
  for(j = 0; j < n; j++) C[A[j]]++;
  for(i = 0; i <= k; i++) C[i+1] = C[i] + C[i+1];
  for(j = n-1; j >= 0; j--){
    B[C[A[j]]-1] = A[j];
    C[A[j]]--;
  } 
}
int main(){
  int i, A[N], *B;
  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&A[i]);
  B = malloc(sizeof(int)*n);
  Counting_Sort(A, B, 10000);
  for(i = 0; i < n; i++){
    if(i > 0) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  free(B);
  return 0;
}
