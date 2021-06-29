#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define pb push_back
#define rep(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < (n); i++)
#define mod (ll)(1e9+7)
#define int ll

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

void trace(int a[], int n) {
  int i;
  rep(i, n) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

void insertionSort(int a[], int n) {
  int i, j, v;
  FOR(i, 1, n) {
    v = a[i];
    j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    trace(a, n);
  }
}

signed main() {
	int n, i, j;
  int a[100];

  cin >> n;
  rep(i, n) cin >> a[i];

  trace(a, n);
  insertionSort(a, n);

  return 0;
}
