#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define VMAX 10000

int B[MAX], C[MAX];

void countingSort(int A[], int B[], int k, int n){
  int i, j;
  for( i = 0 ; i <= k ; i++ ){
    C[i] = 0;
  }
  for( j = 1 ; j <= n ; j++ ){
    C[A[j]]++;
  }
  for( i = 1 ; i <= k ; i++){
    C[i] =  C[i] + C[i-1];
  }
  for( j = n ; j >= 1 ; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  for( i = 1 ; i <= n ; i++ ){
    if( i > 1 ) printf(" ");
    printf("%d", B[i] );
  }
  printf("\n");

}

int main(){
  int A[MAX];
  int n, i, j, k = 0;
  scanf("%d", &n);

  for( i = 0 ; i < n ; i++ ){
    scanf("%d", &A[i+1] );
    if(k < A[i]) k = A[i];
  }

  countingSort(A, B, k, n);

  return 0;
}

