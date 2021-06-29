#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> A, int N) {
  for (int i = 1; i < N; i++) {
    int v = A.at(i), j = i - 1;
    while (j >= 0 && A.at(j) > v) {
      A.at(j + 1) = A.at(j);
      j--;
    }
    A.at(j + 1) = v;

    for (int k = 0; k < N; k++) {
      if (k == N - 1) {
        cout << A.at(k);
      } else {
        cout << A.at(k) << " ";
      }
    }
    cout << endl;
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    if (i == N - 1) {
      cout << A.at(i);
    } else {
      cout << A.at(i) << " ";
    }
  }
  cout << endl;

  insertionSort(A, N);
}
