#include <bits/stdc++.h>
using namespace std;

int selectionSort(vector<int>& A, int N) {
  int cnt = 0;
  for (int i = 0; i < N - 1; i++) {
    int minJ = i;
    for (int j = i + 1; j < N; j++) {
      if (A[j] < A[minJ]) {
        minJ = j;
      }
    }
    if (i != minJ) {
      swap(A[i], A[minJ]);
      cnt++;
    }
  }
  return cnt;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int cnt = selectionSort(A, N);
  cout << A.at(0);
  for (int i = 1; i < N; i++) cout << ' ' << A.at(i);
  cout << endl;
  cout << cnt << endl;
}

