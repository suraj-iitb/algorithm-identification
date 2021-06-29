#include <iostream>

int main() {
  const int ARRAY_SIZE = 100;
  int a[ARRAY_SIZE];
  int n;
  int count = 0;

  std::cin >> n;
  for (int i = 0;i < n;i++) {
    std::cin >> a[i];
  }

  for (int i = 0;i < n;i++) {
    int min_index = i;
    for (int j = i + 1;j < n;j++) {
      if (a[j] < a[min_index]) {
        min_index = j;
      }
    }
    if (a[min_index] < a[i]) {
      int tmp = a[i];
      a[i] = a[min_index];
      a[min_index] = tmp;
      count++;
    }
  }

  for (int i = 0;i < n;i++) {
    int min_index = i;
    for (int j = i + 1;j < n;j++) {
      if (a[j] < a[min_index]) {
        min_index = j;
      }
    }
    if (a[min_index] < a[i]) {
      int tmp = a[i];
      a[i] = a[min_index];
      a[min_index] = tmp;
      count++;
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
