#include <bits/stdc++.h>
using namespace std;

void dump(int* A, int size) {
  for (int i = 0; i < size; ++i) {
    if (i != 0) cout << ' ';
    cout << A[i];
  }
  cout << endl;
}

int main() {
  int A[110];
  int n, i, j, v;

  cin >> n;

  for (i = 0; i < n; ++i) {
    cin >> A[i];
  }

  dump(A,n);
  for (i = 1; i < n; ++i) {
    v = A[i];
    j = i - 1;
    while ( j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      --j;
    }
    A[j + 1] = v;
    dump(A, n);
  }

  return 0;
}
