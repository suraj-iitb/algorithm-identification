#include<stdio.h>
#define N 2000001
int B[N], n;

void CountingSort(int A[], int k){
  int C[k + 1], i, j;
  for(i = 0; i <= k; i++) C[i] = 0;
  for(j = 1; j <= n; j++) C[A[j]]++;
  for(i = 1; i <= k; i++) C[i] = C[i] + C[i - 1];
  for(j = n; j > 0; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
int main(){
  int A[N], i, k = 0;
  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    scanf("%d", &A[i]);
    if(k < A[i]) k = A[i];
  }
  CountingSort(A, k + 1);
  for(i = 1; i <= n; i++){
    printf("%d", B[i]);
    if(i < n)printf(" ");
  }
  printf("\n");
  return 0;
}
