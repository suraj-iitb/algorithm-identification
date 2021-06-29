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

void swap(int* A, int i, int j) {
  int tmp;
  tmp = A[i];
  A[i] = A[j];
  A[j] = tmp;
  return;
}

int bubble_sort(int* A, int n) {
  int swap_cnt = 0;

  for (int i = n - 1; i >= 1; i--) {
    for (int j = 0; j < i; j++) {
      if (A[j] > A[j + 1]) {
        swap(A, j, j + 1);
        swap_cnt += 1;
      }
    }
  }

  return swap_cnt;
}

int main(void) {
  int A[MAX_N], n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  int swap_cnt = bubble_sort(A, n);
  trace(A, n);
  cout << swap_cnt << endl;

  return 0;
}

