#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void printArray(int *A, int N) {
  rep(i, N) {
    std::cout << A[i];
    if (i == N - 1) {
      std::cout << '\n';
    } else {
      std::cout << ' ';
    }
  }
}

void insertionSort(int *A, int N) {
  for (int i = 1; i < N; i++) {
    int v = A[i];
    int j = i - 1;

    while (j >= 0 && v < A[j]) {
      A[j + 1] = A[j];
      j--;
    }

    A[j + 1] = v;

    printArray(A, N);
  }
}

int main() {
  int N;
  std::cin >> N;

  int A[N];
  rep(i, N) { std::cin >> A[i]; }

  printArray(A, N);
  insertionSort(A, N);

  return 0;
}

