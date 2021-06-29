#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; i++)
#define display false //????????????????????¨??????????????¨???

std::vector<int> bubble_sort(std::vector<int> A) {
  int flag = 1;
  int key, count = 0;
  while (flag) {
    flag = 0;
    for (int j = A.size() - 1; j >= 1; j--) {
      if (A[j] < A[j - 1]) {
        key = A[j - 1];
        A[j - 1] = A[j];
        A[j] = key;
        flag = 1;
        count++;
      }
    }
  }
  for (int k = 0; k < A.size(); k++) {
    if (k > 0) {
      std::cout << " ";
    }
    std::cout << A[k];
  }
  std::cout << std::endl;
  std::cout << count << std::endl;
  return A;
}

int main() {
  int N;
  std::cin >> N;
  std::vector<int> A(N);
  rep(i, N) { std::cin >> A[i]; }
  std::vector<int> AA = bubble_sort(A);
  return 0;
}
