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

int bubble_sort(int *A, int N){
  int flag = 1;
  int count = 0;
  while(flag){
    flag = 0;
    for(int j = N - 1; j > 0; j--){
      if(A[j] < A[j-1]){
        int tmp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = tmp;
        flag = 1;
        count++;
      }
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

  int count = bubble_sort(A, N);
  output(A, N, count);

  return 0;
}

