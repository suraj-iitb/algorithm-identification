#include "bits/stdc++.h"

using namespace std;

int BubbleSort(vector<int>& A) {
  int counter = 0;
  for (int i = 0; i < A.size(); ++i) {
    for (int j = A.size() - 1; j >= i + 1; --j) {
      if (A[j] < A[j-1]) {
        swap(A[j], A[j - 1]);
        ++counter;
      }
    }
  }
  return counter;
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (auto& a : A)
    cin >> a;
  int counter = BubbleSort(A);

  for (int i = 0; i < A.size(); ++i) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << counter << endl;
}
