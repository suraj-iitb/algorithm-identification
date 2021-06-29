#include <bits/stdc++.h>
using namespace std;

void out(vector<int> v, int n) {
  for (int i = 0; i < n; i++) {
    if (i == n - 1)
      cout << v[i] << endl;
    else
      cout << v[i] << ' ';
  }
}

void insertionSort(vector<int> A, int n) {
  int v, j;
  for (int i = 1; i < n; i++) {
    v = A[i];
    j = i - 1;
    while (0 <= j && v < A[j]) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    out(A, n);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  out(v, n);
  insertionSort(v, n);
}

