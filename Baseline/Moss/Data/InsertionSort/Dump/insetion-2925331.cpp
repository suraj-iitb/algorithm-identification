#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for ( int i = 0; i < n; i++ ) {
    cin >> a[i];
    if ( i ) cout << " ";    
    cout << a[i];
  }
  cout << endl;

  for ( int i = 1; i < n; i++ ) {
    int v = a[i];
    int j = i-1;
    while ( j >= 0 && a[j] > v ) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    for ( int i = 0; i < n; i++ ) {
      if ( i ) cout << " ";    
      cout << a[i];
    }
    cout << endl;
  }
  
  return 0;
}

