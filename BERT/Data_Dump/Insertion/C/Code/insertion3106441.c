#include <stdio.h>
const int n = 100;
void insertionSort(int A[], int N);


int main(){
  int i, N;
  int A[n];
  scanf("%d", &N);
  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }

  insertionSort(A, N);

  return 0;
}

void insertionSort(int A[], int N){
  int i, j, k, v;
  
  for(k = 0; k < N; k++){
    printf("%d", A[k]);
    if(k == N-1){
      printf("\n");
    }else{
      printf(" ");
    }
  }
  
  for(i = 1; i < N; i++){
    j = i-1;
    v = A[i];

    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }

    A[j+1] = v;
    for(k = 0; k < N; k++){
      printf("%d", A[k]);
      if(k == N-1){
        printf("\n");
      }else{
        printf(" ");
      }
    }

  }
}

