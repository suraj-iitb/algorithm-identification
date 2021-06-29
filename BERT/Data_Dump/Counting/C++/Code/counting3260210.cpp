#include <iostream>
using namespace std;

static const int K = 10001;

void CountingSort(int A[], int B[], int n) {
  int C[K];
  for (int i = 0; i < K; i++) {
    C[i] = 0;
  }
  for (int j = 0; j < n; j++) {
    C[A[j]]++;
  }
  for (int i = 1; i < K; i++) {
    C[i] = C[i] + C[i-1];
  }

  for (int j = n-1; j >= 0; j--) {
    B[C[A[j]]-1] = A[j];
    C[A[j]]--;
  }
}

int main() {
  int n;
  cin >> n;
  int A[n], B[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  CountingSort(A, B, n);
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << B[i];
  }
  cout << endl;
  return 0;
}

