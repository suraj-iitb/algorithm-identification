#include<stdio.h>

int selectionSort(int A[],int N);

int main(void){
  int A[100],N;
  int i;
  int n = 0;

  scanf("%d",&N);
  
  for(i = 0;i < N;i++){
    scanf("%d",&A[i]);
  }

  n = selectionSort(A,N);

  for(i = 0;i < N;i++){
    if(i != 0){
      printf(" ");
    }
    printf("%d",A[i]);
  }
  
  printf("\n%d\n",n);

  return 0;
}



int selectionSort(int A[],int N){
  int i,j;
  int n = 0;
  int temp;
  int minj;

  for(j = 0;j < N-1;j++){
    minj = j;
    for(i = j;i <= N-1;i++){
      if(A[i] < A[minj]){
	minj = i;
      }
    }
    temp = A[j];
    A[j] = A[minj];
    A[minj] = temp;
    if(j != minj){
      n++;
    }
  }
  
  return n;
}


