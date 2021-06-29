#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printer(int *, int);
void CountingSort(int *, int *, int, int);

int main(){
  int i, n, k=0;
  int *A, *B;

  // input
  scanf("%d", &n);
  A = (int *)malloc(sizeof(int) * n);
  B = (int *)malloc(sizeof(int) * n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
    if(k < A[i]) k = A[i];
  }

  CountingSort(A, B, k, n);

  printer(B, n);

  return 0;
}

void printer(int *array, int n){
  int i;
  for(i=0; i<n; i++){
    printf("%d",array[i]);
    if(i != n-1) printf(" ");
    else printf("\n");
  }
}

void CountingSort(int *A, int *B, int k, int n){
  int i, j, *C;

  C = (int *)malloc(sizeof(int) * k+1);
  memset(C, 0, sizeof(int) * k+1);

  for(i=0; i<n; i++)  C[A[i]] ++;

  for(i=1; i<=k; i++)  C[i] += C[i-1];

  for(i=n-1; i>=0; i--){
    B[C[A[i]]-1] = A[i];
    C[A[i]] --;
  }

}

