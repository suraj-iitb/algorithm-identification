#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int ans = 0;

int bubbleSort(vector<int> A, int N){
  bool flag = true;
  while (flag) {
    flag = false;
    for (int j = N-1; j > 0; j--) {
      if (A[j] < A[j-1]) {
        swap(A[j], A[j-1]);
        ans ++;
        flag = true;
      }
    }
  }
  rep(k, N) {
    if (k != N-1)cout << A[k] << " ";
    else cout<< A[k];
  }
  cout<< endl;
  return 0;
}

int main() {
  int N;cin>>N;
  vector<int> A(N);
  rep(i, N) cin>>A[i];

  bubbleSort(A, N);

  cout << ans << endl;
  return 0;
}

