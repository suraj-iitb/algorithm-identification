#include <algorithm>
#include <iostream>
#include <vector>

void print_array(const int a[], int n) {
  for (int i = 0; i < n; ++i) {
    if (i > 0)
      std::cout << " ";
    std::cout << a[i];
  }
  std::cout << std::endl;
}

int bubble_sort(int a[], int n) {
  bool flag = true;
  int count = 0;
  while (flag) {
    flag = false;
    for (int j = n - 1; j > 0; --j) {
      if (a[j] < a[j - 1]) {
        ++count;
        std::swap(a[j], a[j - 1]);
        flag = true;
      }
    }
  }
  return count;
}

int main() {
  int n;
  std::cin >> n;
  int a[101];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int count = bubble_sort(a, n);
  print_array(a, n);
  std::cout << count << std::endl;
}

