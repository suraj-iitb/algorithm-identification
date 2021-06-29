#include <iostream>

void insertionSort(int A[], int N) { // N個の要素を含む0-オリジンの配列A
  for(int j = 0; j < N; j++) {
    std::cout << A[j];
    if(j == N-1) std::cout << std::endl;
    else std::cout << " ";
  }
  for(int i = 1; i < N; i++) {       // for i が 1 から N-1 まで
    int v = A[i];                    //   v = A[i]
    int j = i - 1;                   //   j = i - 1
    while (j >= 0 && A[j] > v) {     //   while j >= 0 かつ A[j] > v
      A[j+1] = A[j];                 //     A[j+1] = A[j]
      j--;                           //     j--
    }
    A[j+1] = v;                      //   A[j+1] = v

    for(int j = 0; j < N; j++) {
      std::cout << A[j];
      if(j == N-1) std::cout << std::endl;
      else std::cout << " ";
    }
  }
}

int main(void){
  int N;
  std::cin >> N;
  int *A = new int[N];
  for(int i = 0; i < N; i++) {
    std::cin >> A[i] ;
  }

  insertionSort(A, N);

  return 0;
}


