#include<stdio.h>
#include<stdlib.h>
int main(){
  int i, j, N, v;
  int *A;

  scanf("%d",&N);
  A = (int *)malloc(sizeof(int) * N);
 
  for( i = 0 ; i < N ; i++ ){
    scanf("%d",&A[i]);
  }
    printf("%d",A[0]);
    for( j = 1 ; j < N ; j++ ){
      printf(" %d",A[j]);
    }
    printf("\n");

  /*   sort   */
  for( i = 1 ; i < N ; i++ ){
    v = A[i];
    j = i - 1;
    while( ( j >= 0 ) && (A[j] > v) ){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;

    printf("%d",A[0]);
    for( j = 1 ; j < N ; j++ ){
      printf(" %d",A[j]);
    }
    printf("\n");
  }

  
  return 0;
}

