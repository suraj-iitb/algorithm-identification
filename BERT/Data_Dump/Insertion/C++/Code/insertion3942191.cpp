#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define rep(i,n) for(int i = 0;i<n;i++)
const long long MOD = 1000000007;

int main(){
  int n; cin >> n;
  int a[n];
  rep(i,n) cin >> a[i];
  rep(i,n){
    int j = i-1;
    int have = a[i];
    while ( j >= 0 && a[j] > have){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = have;
    rep(k,n-1) cout << a[k] << " ";
    cout << a[n-1] << "\n";
  }
}

