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

int selection_sort(int a[], int n) {
  int count = 0;
  for (int i = 0; i < n; ++i) {
    int minj = i;
    for (int j = i; j < n; ++j) {
      if (a[j] < a[minj])
        minj = j;
    }
    if (minj != i) {
      std::swap(a[i], a[minj]);
      ++count;
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

  int count = selection_sort(a, n);
  print_array(a, n);
  std::cout << count << std::endl;
}

