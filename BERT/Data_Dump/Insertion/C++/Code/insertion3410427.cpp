#include <iostream>

#define MAX 1000

void output(int A[MAX], int n) {
  for(int i = 0; i < n; i++) {
    std::cout << A[i];
    if(i != n - 1) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;
}

void insertion_sort(int A[MAX], int n) {
  for(int i = 1; i < n; i++) {
    int v = A[i];
    int j = i - 1;

    while(j >= 0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;

    output(A, n);
  }
}

int main() {
  int n;
  std::cin >> n;

  int A[MAX] = { 0 };
  for(int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  output(A, n);

  insertion_sort(A, n);

  return 0;
}
