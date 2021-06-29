#include <bits/stdc++.h>
using namespace std;

int selectionSort(vector<int> &A, int N) {
  int changeTimes = 0;
  for (int i = 0; i < N; i++) {
    int minj = i;
    for (int j = minj; j < N; j++) {
      if (A[minj] > A[j]) {
        minj = j;
      }
    }
    if (i == minj) {
      continue;
    }
    changeTimes += 1;
    swap(A[i], A[minj]);
  }

  return changeTimes;
};

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  int ans = selectionSort(A, N);
  for (int i = 0; i < N; i++) {
    if (i == N - 1) {
      cout << A[i] << endl;
    } else {
      cout << A[i] << ' ';
    }
  }

  cout << ans << endl;
};

