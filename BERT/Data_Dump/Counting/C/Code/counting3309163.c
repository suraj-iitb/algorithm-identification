#include<stdio.h>

void CountingSort(int *, int *, int);

int C[10000];

int main(){

  int i, n;

  scanf("%d", &n);

  int A[n], B[n];
    
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  CountingSort(A, B, n);

  for(i = 1; i < n; i++){
    printf("%d ", B[i]);
  }
  printf("%d\n", B[i]);


  return 0;
}

void CountingSort(int *A, int *B, int n){

  int i;
  
  for(i = 0; i < 10000; i++){
    C[i] = 0;
  }

  /* C[i] に i の出現数を記録する */
  for(i = 0; i < n; i++){
    C[A[i]]++;
  }

  /* C[i] に i 以下の数の出現数を記録する*/
  for(i = 1; i <= 10000; i++){
    C[i] = C[i] + C[i-1];
  }
  
  for(i = n-1; i >= 0; i--){ 
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
}      

