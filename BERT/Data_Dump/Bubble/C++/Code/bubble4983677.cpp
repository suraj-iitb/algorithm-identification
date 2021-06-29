#include <bits/stdc++.h>
using namespace std;

int bubbleSort(vector<int> &A, int N) {
  int flag = 1, cnt = 0;
  while (flag) {
    flag = 0;
    for (int j = N - 1; j > 0; j--) {
      if (A.at(j) < A.at(j - 1)) {
        swap(A.at(j), A.at(j - 1));
        cnt++;
        flag = 1;
      }
    }
  }
  return cnt;
}

int main() {
  int N, cnt;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  cnt = bubbleSort(A, N);

  for (int i = 0; i < N; i++) {
    cout << A.at(i);
    if (i < N - 1) cout << " ";
  }
  cout << endl;
  cout << cnt << endl;
}
