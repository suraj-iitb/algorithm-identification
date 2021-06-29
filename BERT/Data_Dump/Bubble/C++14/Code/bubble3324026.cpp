#include <iostream>

void trace(int* arr, const int& size) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i];
    if (i == size - 1) {
      std::cout << "\n";
    } else {
      std::cout << ' ';
    }
  }
}

void swap(int* arr, const int& first, const int& second) {
  int buf = arr[first];
  arr[first] = arr[second];
  arr[second] = buf;
}
int main() {
  int n;
  std::cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  int swapCount = 0;
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      if (arr[j] < arr[j - 1]) {
        swap(arr, j, j - 1);
        swapCount++;
      }
    }
  }
  trace(arr, n);
  std::cout << swapCount << std::endl;
  return 0;
}

