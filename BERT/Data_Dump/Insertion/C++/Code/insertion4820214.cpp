#include <iostream>
using namespace std;

static const int MAX_N = 100;

void trace(int* A, int n) {
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
  return;
}

void insertion_sort(int* A, int n) {
  int i, j, key;

  for (i = 1; i < n; i++) {
    key = A[i];
    j = i - 1;

    while (j >= 0 && A[j] > key) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;
    trace(A, n);
  }

  return;
}

int main(void) {
  int A[MAX_N], n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  trace(A, n);
  insertion_sort(A, n);

  return 0;
}

