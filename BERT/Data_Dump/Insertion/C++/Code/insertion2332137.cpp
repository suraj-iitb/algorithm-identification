#include <bits/stdc++.h>
#include <stdlib.h>

void showA(int *A, int N){

  for(int i = 0; i < N; i++){
    if(i < N-1)
      std::cout << A[i] << ' ';
    else
      std::cout << A[i] << std::endl;
  }

  return;

}


void insertionSort(int *A, int N){

  showA(A, N);

  int v, j;
  for(int i=1; i<N; i++){
    v = A[i];
    j = i - 1;

    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }

    A[j+1] = v;

    showA(A, N);
  }

  return;

}


int main(){
  int N;
  int* A;

  std::cin >> N;

  A = (int*)malloc( sizeof(int) * N );

  for(int i = 0; i < N; i++){
    std::cin >> A[i];
  }

  insertionSort(A, N);

  return 0;
}
