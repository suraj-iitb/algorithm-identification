#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int insertionSort(vector<ll> a, int n) {
  rep(i, n) {
    if (i != n-1) cout << a[i] << " ";
    else cout << a[i];
  }
  cout << endl;

  for(int i = 1; i < n; i ++) {
    int v = a[i];
    int j = i-1;
    while (0 <= j && v < a[j]) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    rep(i, n) {
      if (i != n-1) cout << a[i] << " ";
      else cout << a[i];
    }
    cout<<endl;
  }
  return 0;
}

int main()
{
  ll n;cin>>n;
  vector<ll> a(n);
  rep(i, n) cin>>a[i];
  insertionSort(a, n);
}
