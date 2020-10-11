#include <stdio.h>

#define MAX 100


void bubbleSort(int *A , int N){
  int i,j;
  int temp;
  int minj;
  int num = 0;

  for(i = 0 ; i < N ; i++){
    minj = i;
    for( j = i ; j < N ; j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
    if(i != minj) num++;
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
  }
  for(i = 0 ; i < N ; i++){
    printf("%d", A[i]);
    if(i != N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n", num);

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

  bubbleSort(A, N);


  return 0;
}
