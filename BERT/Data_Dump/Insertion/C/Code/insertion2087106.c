#include <stdio.h>

#define MAX 100


void insertion(int *A , int N){
  int i ,j;
  int v;

  for(i = 0 ; i <= N-1 ; i++){
    v = A[i];
    j = i-1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    for( j = 0 ; j < N ; j++){
      printf("%d", A[j]);
      if( j != N-1) printf(" ");
    }
    printf("\n");
  }
  return;
}

int main(void){

  int N;
  int A[MAX];
  int i;

  scanf("%d",&N);

  for(i = 0 ; i < N ; i++){
    scanf("%d",&A[i]);
  }

  insertion(A, N);


  return 0;
}
