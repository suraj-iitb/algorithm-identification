#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())

using namespace std;
using ll = long long;

template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T> constexpr T INF = numeric_limits<T>::max() / 2;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> arr(n);
  REP(i, n) cin >> arr.at(i);
  int nswap = 0;
  REP(i, n) {
    int minj = i;
    FOR(j, i, n) {
      if (arr.at(minj) > arr.at(j))
        minj = j;
    }
    if (minj != i) {
      swap(arr.at(minj), arr.at(i));
      nswap++;
    }
  }
  REP(i, n) cout << (i ? " " : "") << arr.at(i);
  cout << endl << nswap << endl;

  return 0;
}
