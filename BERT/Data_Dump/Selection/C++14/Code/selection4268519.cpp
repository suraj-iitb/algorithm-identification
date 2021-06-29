#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
const int inf = 1001001001;

int main()
{
  int n; cin >> n;
  vector<int> a(n, 0);
  rep(i, n) cin >> a[i];

  int ans = 0;
  rep(i, n) {
    int minj = i;
    for (int j=i; j<n; j++) {
      if (a[j] < a[minj]) minj = j;
    }
    if (i < minj) ans++;
    swap(a[i], a[minj]);
  }
  rep(i, n) {
    if (i == 0) cout << a[i];
    else cout << " " << a[i];
  }
  cout << endl;
  cout << ans << endl;

  return 0;
}

