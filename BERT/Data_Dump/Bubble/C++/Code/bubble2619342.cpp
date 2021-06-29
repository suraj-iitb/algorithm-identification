#include <iostream>

int main() {
  const int ARR_SIZE = 100;
  int a[ARR_SIZE];
  int n;
  bool sorted;
  int count = 0;

  std::cin >> n;
  for (int i = 0;i < n;i++) {
    std::cin >> a[i];
  }

  sorted = false;
  while (!sorted) {
    sorted = true;
    for (int i = n - 1; i > 0; i--) {
      if (a[i] < a[i - 1]) {
        int tmp = a[i];
        a[i] = a[i - 1];
        a[i - 1] = tmp;
        sorted = false;
        count++;
      }
    }
  }

  for (int i = 0; i < n;i++) {
    if (i == n - 1) {
      std::cout << a[i] << std::endl;
    } else {
      std::cout << a[i] << " ";
    }
  }
  std::cout << count << std::endl;

  return 0;
}
