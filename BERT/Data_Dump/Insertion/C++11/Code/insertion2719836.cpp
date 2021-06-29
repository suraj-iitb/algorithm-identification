#include <iostream>
#include <array>

#include <cstdio>

void printArray(int A[], int N) {
  for (auto i = 0; i < N; i++) {
    std::cout << (i != 0 ? " " : "") << A[i];
  }
  std::cout << std::endl; 
}

void insersionSort(int A[], int N) {
  int v, j;
  //  for (auto i = 1; i < N - 1; i++) {
  for (auto i = 1; i < N; i++) {
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v) {
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

  std::array<int, 100> A;
  for (auto i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  printArray(A.data(), N);
  insersionSort(A.data(), N);
}

