#include <bits/stdc++.h>
#include <stdlib.h>

int bubbleSort(int* A, int N){

  bool flag = true;
  int count = 0;

  while(flag){
    flag = false;

    for(int i = N-1; i > 0; i--){
      if(A[i] < A[i-1]){
        int tmp = A[i];
        A[i] = A[i-1];
        A[i-1] = tmp;
        flag = true;
        count++;
      }
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

  int c = bubbleSort(A, N);

  showA(A, N);
  std::cout << c << std::endl;

  return 0;
}
