#include <stdio.h>

#define MAX 100


void bubbleSort(int *A , int N){
  int j;
  int temp;
  int flag;
  int num = 0;

  flag = 1;

  while(flag){
    flag = 0;
    for( j = N-1 ; j > 0 ; j--){
      if(A[j] < A[j-1]){
        temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp;
        flag = 1;
        num++;
      }
    }
  }
  for(j = 0 ; j < N ; j++){
    printf("%d", A[j]);
    if(j != N-1) printf(" ");
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
