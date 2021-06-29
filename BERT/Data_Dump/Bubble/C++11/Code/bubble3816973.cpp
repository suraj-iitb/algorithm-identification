#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define BR "\n"
#define SP " "
#define SHOW(x) for(int i = 0; i < x.size(); i++) { cout << x[i] << SP; } cout << BR;
#define SHOW2(x) for(int j = 0; j < x.size(); j++) { SHOW(x[j]); } cout << BR;

int main() {
  ll N;
  cin >> N;

  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  ll ans = 0;
  for (int i = 1; i < N; i++) {
    for (int j = N - 1; j >= i; j--) {
      if (A[j-1]>A[j]) {
        swap(A[j-1], A[j]);
        ans++;
      }
    }
  }

  cout << A[0];
  for (int i = 1; i < N; i++) {
    cout << SP << A[i];
  }
  cout << BR;
  cout << ans << "\n";
  return 0;
}
