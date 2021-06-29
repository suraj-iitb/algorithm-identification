#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;
  vector<ll> A(N); for (ll i = 0; i < N; i++) cin >> A[i];

  for (ll i = 0; i < N; i++) {
    ll temp = A[i];
    ll j = i - 1;
    while (j >= 0 && A[j] > temp) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = temp;
    cout << A[0]; for (int i = 1; i < A.size(); i++) { cout << ' ' << A[i]; }
    cout << '\n';
  }
  return 0;
}
