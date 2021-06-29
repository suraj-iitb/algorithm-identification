#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int selectionSort(int *a, int n) {
  int cnt = 0;
  rep(i, n) {
    int min = i;
    for (int j = i; j < n; j++) {
      if (a[j] < a[min])
        min = j;
    }

    if (min == i)
      continue;

    int temp = a[i];
    a[i] = a[min];
    a[min] = temp;
    cnt++;
  }

  return cnt;
}

int main() {
  int n;
  std::cin >> n;

  int a[n];
  rep(i, n) std::cin >> a[i];

  int cnt = selectionSort(a, n);

  rep(i, n) {
    std::cout << a[i];
    if (i == n - 1)
      std::cout << '\n';
    else
      std::cout << ' ';
  }

  std::cout << cnt << '\n';

  return 0;
}
