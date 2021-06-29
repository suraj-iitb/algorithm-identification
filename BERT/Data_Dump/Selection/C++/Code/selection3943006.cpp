#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define rep(i,n) for(int i = 0;i<n;i++)
const long long MOD = 1000000007;

int main(){
  int n; cin >> n;
  int a[n]; rep(i, n) cin >> a[i];
  int ans = 0;
  for(int i = 0; i < n; i++){
    int selectMin = i;
    for(int j = i+1; j<n; j++){
      if(a[j] < a[selectMin]) selectMin = j;
    }
    swap(a[selectMin], a[i]);
    if(selectMin != i) ans++;
  }
  rep(i, n-1) cout << a[i] << " ";
  cout << a[n-1] << "\n"; 
  cout << ans << "\n";
}
