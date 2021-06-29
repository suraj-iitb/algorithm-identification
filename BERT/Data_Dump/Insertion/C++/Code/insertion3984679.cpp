#include<stdio.h>

using namespace std;

int output(int *A, int N){
  for(int i = 0; i < N; i++){
    printf("%d", A[i]);
    if(i < N - 1){
      printf(" ");
    }
  }
  printf("\n");
  return 0;
}

int insertion_sort(int *A, int N){
  for(int i = 1; i < N; i++){
    int v = A[i];
    int j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j + 1] = A[j];
      A[j] = v;
      j--;
    }
    output(A, N);
  }
  return 0;
}

int main(void){
  int N;
  int A[101];
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }
  output(A, N);
  insertion_sort(A, N);
  return 0;
}

