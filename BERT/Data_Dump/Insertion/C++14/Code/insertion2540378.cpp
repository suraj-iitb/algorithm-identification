#include "bits/stdc++.h"

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (auto& a : A)
    cin >> a;
  
  cout << A[0];
  for (int p = 1; p < n; ++p)
    cout << " " << A[p];
  cout << endl;

  for (int i = 1; i < n; ++i) {
    int key = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > key) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;
    cout << A[0];
    for (int p = 1; p < n; ++p)
      cout << " " << A[p];
    cout << endl;
  }
  
}
