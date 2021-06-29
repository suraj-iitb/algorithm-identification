#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10001;

void backetSort(int *A, int *B, int n) {
  int C[MAX] = {};

  for (int i = 0; i < n; i++) C[A[i]]++;
  for (int i = 1; i < MAX; i++) C[i] = C[i] + C[i-1];
  for (int i = n - 1; i >= 0; i--) {
    B[C[A[i]]-1] = A[i];
    C[A[i]]--;
  }
}

int main() {
  int n;
  cin >> n;
  int *A = new int[n];
  for (int i = 0; i < n; i++) cin >> A[i];
  int *B = new int[n];
  fill_n(B, n, 0);

  backetSort(A, B, n);

  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << B[i];
  }
  cout << endl;

  return 0;
}
