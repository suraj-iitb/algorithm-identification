#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

void printArray(int *A, int n) {
  rep(i, n) {
    std::cout << A[i];
    if (i == n - 1)
      std::cout << '\n';
    else
      std::cout << ' ';
  }
}

void insertionSort(int *A, int n) {
  rep(i, n - 1) {
    int j = i + 1;
    int v = A[j];
    for (j = i; j >= 0; --j) {
      if (v < A[j])
        A[j + 1] = A[j];
      else
        break;
    }
    A[j + 1] = v;
    printArray(A, n);
  }
}

int main() {
  int n;
  std::cin >> n;
  int A[n];
  rep(i, n) std::cin >> A[i];

  printArray(A, n);
  insertionSort(A, n);

  return 0;
}

