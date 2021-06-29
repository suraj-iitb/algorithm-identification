#include "bits/stdc++.h"

using namespace std;

int SelectionSort(vector<int>& A) {
  int counter = 0;
  for (int i = 0; i < A.size(); ++i) {
    int mini = i;
    for (int j = i; j < A.size(); ++j) {
      if (A[j] < A[mini]) {
        mini = j;
      }
    }
    swap(A[i], A[mini]);
    if(A[i] != A[mini])  ++counter;
  }
  return counter;
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (auto& a : A)
    cin >> a;
  int counter = SelectionSort(A);

  for (int i = 0; i < A.size(); ++i) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << counter << endl;
}
