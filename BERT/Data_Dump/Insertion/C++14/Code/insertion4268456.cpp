#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;

int main()
{
  int n; cin >> n;
  vector<int> a(n, 0);
  rep(i, n) cin>>a[i];

  rep(i, n) {
    int v = a[i];
    int j = i-1;
    while (j>=0 && a[j]>v) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    rep(k, n) {
      if (k==0) cout << a[k];
      else cout << " " << a[k];
    }
    cout << endl;
  }

  return 0;
}

