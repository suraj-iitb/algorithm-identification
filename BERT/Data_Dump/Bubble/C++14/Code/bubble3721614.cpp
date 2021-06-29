#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  bool flag = true;
  int ret = 0;
  while (flag) {
    flag = false;
    for (int i = N-1; 1 <= i; i--) {
      if (A[i] < A[i-1]) {
        swap(A[i], A[i-1]);
        flag = true;
        ret++;
      }
    }
  }
  cout << A[0];
  for (int i = 1; i < N; i++) cout << ' ' << A[i];
  cout << endl;
  cout << ret << endl;
}