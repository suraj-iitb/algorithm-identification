#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)

int main() {
  ll N;
  cin >> N;
  vector<ll> v(N);
  rep(i, N) { cin >> v[i]; }
  ll count = 0;
  ll i = 0;
  bool frag = true;
  while (frag) {
    frag = false;
    for (ll k = N - 1; k >= i + 1; --k) {
      if (v[k] < v[k - 1]) {
        ll a = v[k];
        v[k] = v[k - 1];
        v[k - 1] = a;
        frag = true;
        ++count;
      }
    }
    ++i;
  }

  rep(j, N - 1) { cout << v[j] << ' '; }
  cout << v[N - 1] << endl;

  cout << count << endl;

  return 0;
}
