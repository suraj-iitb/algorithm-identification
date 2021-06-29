#include <bits/stdc++.h>

void printArray(int a[], int n) {
  std::cout << a[0];
  for (int i = 1; i < n; i++) {
    std::cout << " " << a[i];
  }
  std::cout << std::endl;
}

void insertionSort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    printArray(a, n);
  }
}

int main() {
  int n;
  std::cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  printArray(a, n);
  insertionSort(a, n);
}
