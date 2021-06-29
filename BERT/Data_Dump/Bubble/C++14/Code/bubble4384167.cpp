#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)

int cnt = 0;

void bubbleSort(int *A, int n) {
  rep(i, n) {
    for (int j = n - 1; j > i; --j) {
      if (A[j] < A[j - 1]) {
        int temp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = temp;
        cnt++;
      }
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  int A[n];
  rep(i, n) std::cin >> A[i];

  bubbleSort(A, n);

  rep(i, n) {
    std::cout << A[i];
    if (i == n - 1)
      std::cout << '\n';
    else
      std::cout << ' ';
  }

  std::cout << cnt << '\n';
  return 0;
}
