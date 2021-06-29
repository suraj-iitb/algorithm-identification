#include <bits/stdc++.h>
using namespace std;

int output(vector<int> A, int N) {
  for (int i = 0; i < N; i++) {
    if (i == N - 1) {
      cout << A.at(i) << endl;
    } else {
      cout << A.at(i) << " ";
    }
  }
}

int insertionSort(vector<int>A, int N) {
  int v, j;

  for (int i = 0; i < N; i++) {
    v = A.at(i);
    j = i - 1;

    while (j >= 0 && A.at(j) > v) {
      A.at(j + 1) = A.at(j);
      j--;
    }

    A.at(j + 1) = v;

    output(A, N);
  }
}

int main() {
  int N;
  vector<int> A(N);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  insertionSort(A, N);
}

