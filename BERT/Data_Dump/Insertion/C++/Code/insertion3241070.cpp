#include <iostream>
using namespace std;

void print_result(int* A, int n) {
  for (size_t k = 0; k < n; ++k) {
    if (k < n-1) {
      cout << A[k] << " ";
    } else {
      cout << A[k];
    }
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  int A[n-1];
  for (size_t i = 0; i < n; ++i) {
    cin >> A[i];
  }
  print_result(A, n);
  for (size_t i = 1; i < n; ++i) {
    int v = A[i];
    int j = i-1;
    while (j >=0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    print_result(A, n);
  }
  return 0;
}

