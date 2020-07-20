#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define rep(i,n) for(int i = 0;i<n;i++)
const long long MOD = 1000000007;

int main(){
  int n; cin >> n;
  int a[n];
  for(int i = 0; i<n;i++) cin >> a[i];
  int ans = 0;
  for(int i = 1; i<n;i++){
    int j = i;
    while(j < n && j >= 1){
      if(a[j] < a[j-1]){
        swap(a[j], a[j-1]);
        ans++;
      }
      j--;
    }
  }
  rep(i, n-1) cout << a[i] << " ";
  cout << a[n-1] << "\n";
  cout << ans << "\n";
}
