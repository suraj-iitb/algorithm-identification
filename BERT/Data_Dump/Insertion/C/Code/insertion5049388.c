#include <stdio.h>

void trace(int A[], int N){
  int i;
  for(i = 0; i < N; i++){
    if(i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void insertionSort(int A[],int N){
  int j, i, k;
  for(i = 1; i < N; i++){
    k = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > k){
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = k;
    trace(A,N);
  }
}

int main() {
  int i, j, N;
  int A[100];

  scanf("%d", &N);
  for(i = 0; i < N; i++) scanf("%d", &A[i]);

  trace(A,N);
  insertionSort(A,N);

  return 0;
}

  

