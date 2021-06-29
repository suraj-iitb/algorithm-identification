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

void insertion_sort(int a[], int n) {
  for (int i = 0; i < n; ++i) {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    print_array(a, n);
  }
}

int main() {
  int n;
  std::cin >> n;
  int a[100];
  for (int i = 0; i < n; ++i)
    std::cin >> a[i];

  insertion_sort(a, n);
}

