#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  int sw = 0;
  REP(i, N) {
    int minj = i;
    for(int j = i; j < N; j++) {
      if(A[minj] > A[j]) {
        minj = j;
      }
    }
    swap(A[i], A[minj]);
    if(i != minj)
      sw++;
  }
  REP(i, N) {
    cout << A[i];
    if(i < N - 1)
      cout << " ";
  }
  cout << endl << sw << endl;
  return 0;
}
