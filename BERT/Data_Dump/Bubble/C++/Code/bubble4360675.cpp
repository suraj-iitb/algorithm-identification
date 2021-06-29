#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int bubbleSort(int *A, int N) {
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = N - 1; j > i; j--) {
      if (A[j] < A[j - 1]) {
        swap(&A[j], &A[j - 1]);
        cnt++;
      }
    }
  }

  return cnt;
}

int main() {
  int n;
  std::cin >> n;
  int a[n];
  rep(i, n) std::cin >> a[i];

  int cnt = bubbleSort(a, n);

  rep(i, n) {
    std::cout << a[i];
    if (i == n - 1) {
      std::cout << '\n';
    } else {
      std::cout << ' ';
    }
  }

  std::cout << cnt << '\n';

  return 0;
}
