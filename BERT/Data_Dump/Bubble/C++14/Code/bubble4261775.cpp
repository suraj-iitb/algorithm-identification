#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;
  vector<ll> A(N); for (ll i = 0; i < N; i++) cin >> A[i];

  ll cnt = 0;
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N - 1 - i; j++) {
      if (A[j] > A[j + 1]) {
        swap(A[j], A[j + 1]);
        cnt++;
      }
    }
  }
  cout << A[0]; for (int i = 1; i < A.size(); i++) { cout << ' ' << A[i]; }
  cout << '\n' << cnt << '\n';
  return 0;
}
