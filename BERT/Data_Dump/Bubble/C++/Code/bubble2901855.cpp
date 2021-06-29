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

int bubbleSort(int a[], int n) {
  int result = 0;
  int flag;
  flag = 1;
  for (int j = 0; flag; j++) {
    flag = 0;
    for(int i = n - 1; i >= j + 1; i--) {
      if (a[i] < a[i - 1]) {
        swap(a[i], a[i - 1]);
        flag = 1;
        result++;
      }
    }
  }
  return result;
}

signed main() {
	int n, a[100], result;
  cin >> n;
  rep(i, n) cin >> a[i];
  
  result = bubbleSort(a, n);

  rep(i, n) {
    if (i == n - 1) {
      cout << a[i] << endl;
      break;
    }
    cout << a[i] << " ";
  }
  cout << result << endl;
}
