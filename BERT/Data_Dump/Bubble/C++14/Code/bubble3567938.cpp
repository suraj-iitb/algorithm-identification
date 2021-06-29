#include <bits/stdc++.h>
using namespace std;

int bubbleSort(vector<int>& A, int N) {
  bool flag = true;
  int swaps = 0;
  while (flag) {
    flag = false;
    for (int j = N - 1; j > 0; j--) {
      if (A[j] < A[j - 1]) {
        int tmp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = tmp;
        swaps++;
        flag = true;
      }
    }
  }
  return swaps;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int swaps = bubbleSort(A, N);
  cout << A.at(0);
  for (int i = 1; i < N; i++) cout << ' ' << A.at(i);
  cout << endl << swaps << endl;
}

