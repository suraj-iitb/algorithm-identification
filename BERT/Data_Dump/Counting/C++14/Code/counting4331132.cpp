#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

void solve(){
  int n; cin >> n;
  int a[n], c[10001] = {0}, ans[n + 1];
  int maxa = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    maxa = max(a[i], maxa);
    c[a[i]]++;
  }
  for(int i = 1; i <= maxa; i++){
    c[i] += c[i - 1];
  }

  for(int i = 0; i < n; i++){
    ans[c[a[i]]] = a[i];
    c[a[i]]--;
  }
  for(int i = 1; i <= n - 1; i++){
    cout << ans[i] << " ";
  }
  cout << ans[n] << endl;

  return;
}

int main(){
  solve();
  return 0;
}

