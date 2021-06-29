#include <iostream>

int main() {
  const int ARRAY_SIZE = 100;
  int a[ARRAY_SIZE];
  int n;

  std::cin >> n;;
  for (int i = 0;i < n;i++) {
    std::cin >> a[i];
  }

  for (int i = 0;i < n;i++) {
    if (i == n - 1) {
      std::cout << a[i] << std::endl;
    } else {
      std::cout << a[i] << " ";
    }
  }

  for (int i = 1; i < n; i++) {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v)  {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;

    for (int i = 0;i < n;i++) {
      if (i == n - 1) {
        std::cout << a[i] << std::endl;
      } else {
        std::cout << a[i] << " ";
      }
    }
  }
  return 0;
}
