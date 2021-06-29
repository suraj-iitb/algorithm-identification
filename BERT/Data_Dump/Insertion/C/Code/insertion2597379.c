#include<stdio.h>

void sort(int A[], int N){
  int i, j, v;
  for( i = 1; i < N; i++){
    v = A[i];
    j = i - 1;
    for( ; j >= 0 && A[j] > v; j--){
      A[j + 1] = A[j];
    }
    A[j + 1] = v;
    space(A, N);
  }
}

void space(int A[], int N){
  int i;
  for( i = 0; i < N; i++){
    if( i > 0 ){
      printf(" ");
    }
    printf("%d", A[i]);
  }
  printf("\n");
}

int main(void){
  int N, i, j;
  int A[100];
  
  scanf("%d", &N);
  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }
  space(A, N);
  sort(A, N);
}
