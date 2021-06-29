#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; i++)
#define display true

std::vector<int> insertion_sort(std::vector<int> A) {
  int key, j;

#if display
  for (int k = 0; k < A.size(); k++) {
    if (k > 0) {
      std::cout << " ";
    }
    std::cout << A[k];
  }
  std::cout << std::endl;
#endif

  for (int i = 1; i < A.size(); i++) {
    key = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > key) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;

#if display
    for (int k = 0; k < A.size(); k++) {
      if (k > 0) {
        std::cout << " ";
      }
      std::cout << A[k];
    }
    std::cout << std::endl;
#endif
  }
  return A;
}

int main() {
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  rep(i, N) { std::cin >> A[i]; }
  std::vector<int> AA = insertion_sort(A);
  return 0;
}
