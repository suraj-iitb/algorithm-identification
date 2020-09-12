#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for ( int i = 0; i < n; i++ ) cin >> a[i];

  int cnt = 0;
  for ( int i = 0; i < n; i++ ) {
    int minj = i;
    for ( int j = i; j < n; j++ ) {
      if ( a[j] < a[minj] ) {
	minj = j;
      }
    }
    if ( a[i] != a[minj] ) {
      swap(a[i], a[minj]);
      cnt++;
    }
  }

  for ( int i = 0; i < n; i++ ) {
    if ( i ) cout << " ";
    cout << a[i];
  }
  cout << endl;

  cout << cnt << endl;
  
  return 0;
}

