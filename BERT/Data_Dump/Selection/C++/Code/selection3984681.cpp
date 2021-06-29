#include<stdio.h>

int output(int *A, int N, int count){
  for(int i = 0; i < N; i++){
    printf("%d", A[i]);
    if(i < N - 1){
      printf(" ");
    }
  }
  printf("\n");

  printf("%d\n", count);

  return 0;
} 

int selection_sort(int *A, int N){
  int count = 0;
  for(int i = 0; i < N; i++){
    int minj = i;
    for(int j = i; j < N; j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
    if(i != minj){
      int tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
      count++;
    }
  }

  return count;
}
    
int main(void){
  int N;
  int A[101];

  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }

  int count = selection_sort(A, N);
  output(A, N, count);

  return 0;
}

