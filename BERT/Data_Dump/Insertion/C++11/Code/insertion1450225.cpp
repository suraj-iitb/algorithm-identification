#include <bits/stdc++.h>

void print_array(int A[], int N) {
  for(int i = 0; i < N-1; ++i) {
    std::cout << A[i] << " ";
  }
  std::cout << A[N-1] << std::endl;
}

void insertionSort(int A[], int N) {
  int v;
  int j;
  for(int i = 1; i < N; ++i) {
    print_array(A, N);
    v = A[i];
    j = i-1;
    while( j >= 0 and A[j] > v ) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
  }
  print_array(A, N);
}

int main(void) {

  int N;
  int A[128];

  std::cin >> N;
  for(int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }

  insertionSort(A, N);
  
  return 0;
}
