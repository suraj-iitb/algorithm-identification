#include <bits/stdc++.h>
#include <stdlib.h>

int selectionSort(int* A, int N){

  int count = 0;
  int minj;

  for(int i = 0; i < N; i++){
    minj = i;
    for(int j = i; j < N; j++){
      if(A[j] < A[minj])
        minj = j;
    }

    if(minj != i){
      int tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
      count++;
    }
  }

  return count;

}

void showA(int *A, int N){

  for(int i = 0; i < N; i++){
    if(i < N-1)
      std::cout << A[i] << ' ';
    else
      std::cout << A[i] << std::endl;
  }

  return;

}


int main(){
  int* A;
  int N;

  std::cin >> N;

  A = (int*)malloc(sizeof(int) * N);

  for(int i = 0; i < N; i++){
    std::cin >> A[i];
  }

  int c = selectionSort(A, N);

  showA(A, N);
  std::cout << c << std::endl;

  return 0;
}
