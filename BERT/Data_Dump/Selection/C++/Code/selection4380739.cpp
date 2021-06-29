#include <bits/stdc++.h>
using namespace std;

// N 個の要素を含む 0-オリジンの配列 A
int selectionSort(vector<int> &A, int N) {
  int minj;
  int count = 0;

  for (int i = 0; i < N; i++) {
    minj = i;

    for (int j = i; j < N; j++) {
      if (A.at(j) < A.at(minj)) {
        minj = j;
      }
    }

    if (i != minj) {
      swap(A.at(i), A.at(minj));
      count++;
    }
  }

  return count;
}

int main() {
  int N;
  cin >> N;

  vector<int> A(N);

  for (int i = 0; i < N; i++) cin >> A.at(i);

  int count = selectionSort(A, N);

  for (int i = 0; i < N; i++) {
    if (i != N - 1) {
      cout << A.at(i) << " ";
    } else {
      cout << A.at(i) << endl;
    }
  }

  cout << count << endl;
}

