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

int selectionSort(int a[], int n) {
  ll result = 0, minj = 0, i, j;
  for (i = 0; i < n - 1; i++) {
    minj = i;
    for(j = i; j < n; j++) {
      if (a[j] < a[minj]) minj = j;
    }
    swap(a[i], a[minj]);
    if (i != minj) result++;
  }
  return result;
}

signed main() {
	ll n, a[100], result;
  cin >> n;
  rep(i, n) cin >> a[i];

  result = selectionSort(a, n);

  rep(i, n) {
    if (i == n - 1) {
      cout << a[i] << endl;
      break;
    }
    cout << a[i] << " ";
  }
  cout << result << endl;
}
