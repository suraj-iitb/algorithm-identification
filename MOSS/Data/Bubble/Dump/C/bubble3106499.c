#include <stdio.h>

void bubbleSort(int A[], int N);
void swap(int *a, int *b);

int main(){
  int N;
  int i;
  int A[100];
  int count;

  scanf("%d", &N);
  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }

  bubbleSort(A, N);
  return 0;
}

void bubbleSort(int A[], int N){
  int count = 0;
  int flag = 1;
  int i, j;
  while(flag){
    flag = 0;

    for(j = N-1; j >= 1; j--){
      if (A[j] < A[j-1]){
        swap(&A[j], &A[j-1]);
        flag = 1;
        count++;
      }
    }
  }

  for (i = 0; i < N; i++){
    printf("%d", A[i]);
    if(i == N-1){
      printf("\n");
    }else{
      printf(" ");
    }
  }
  printf("%d\n", count);
}

void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

