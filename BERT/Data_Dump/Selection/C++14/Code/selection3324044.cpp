#include <iostream>

void trace(int* arr, int& size) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i];
    std::cout << (i == size - 1 ? '\n' : ' ');
  }
}

void swap(int* arr, int& a, int& b) {
  int buf = arr[a];
  arr[a] = arr[b];
  arr[b] = buf;
}

int selectionSort(int* arr, int& size) {
  int swp = 0;
  for (int i = 0; i < size; i++) {
    int min = i;
    for (int j = i; j < size; j++) {
      if (arr[j] < arr[min]) min = j;
    }
    if (i != min) {
      swap(arr, i, min);
      swp++;
    }
  }
  return swp;
}

int main() {
  int n;
  std::cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  int swp = selectionSort(arr, n);
  trace(arr, n);
  std::cout << swp << std::endl;
  return 0;
}

