#include<stdio.h>
 
int selectionSort(int A[], int N){
  int minj;
  int sw = 0;
  int i, j, v;
  for ( i = 0; i < N; i++) {
    minj = i;
    for ( j = i; j < N; j++) {
      if (A[j] < A[minj]) {
        minj = j;
      }
    }
    v = A[i]; A[i] = A[minj]; A[minj] = v;
    if( i != minj) sw++;
  }
  return sw;
}
 
int main(){
  int A[100], N, i, sw;
 
  scanf("%d", &N);
  for ( i = 0; i < N; i++) scanf("%d", &A[i]);
 
  sw = selectionSort(A, N);
 
  for ( i = 0; i < N; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", sw);
 
  return 0;
}
