#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int selectionSort(int n, vector<int> &a){
  int ans = 0;
  rep(i, n){
    int minj = i;
    for (int j = i; j<n; j++){
      if (a[minj] > a[j]){
        minj = j;
      }
    }
    if (i != minj){
      swap(a[i], a[minj]);
      ans++;
    }
  }
  return ans;
}

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i, n) cin>>a[i];
  int ans = selectionSort(n, a);
  rep(i, n-1) cout << a[i] << " ";
  cout << a[n-1] <<endl;
  cout << ans <<endl;
  return 0;
}
