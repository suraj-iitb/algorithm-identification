#include <iostream>
#include <algorithm>

using namespace std;

const int VMAX = 10000;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  unsigned short *A, *B;
  int C[VMAX + 1] = {};

  cin >> n;
  A = new unsigned short[n + 1];
  B = new unsigned short[n + 1];

  for (int i = 1; i <= n; ++i)
    cin >> A[i];

  for (int i = 1; i <= n; ++i)
    ++C[A[i]];

  for (int i = 1; i <= VMAX; ++i)
    C[i] += C[i - 1];

  for (int i = n; i > 0; --i) {
    B[C[A[i]]] = A[i];
    --C[A[i]];
  }

  for (int i = 1; i <= n; ++i) {
    cout << B[i];
    if (i == n) cout << "\n";
    else cout << " ";
  }

  delete[] A;
  delete[] B;
}


