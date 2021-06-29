#include <iostream>
#include <vector>
using namespace std;

void solve(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int cnt = 0;
  for(int i = 1; i <= n - 1; i++){
    for(int j = n - 1; j >= i; j--){
      if(a[j] < a[j - 1]){
        int t = a[j];
        a[j] = a[j - 1];
        a[j - 1] = t;
        cnt++;
      }
    }
  }
  for(int i = 0; i < n - 1; i++){
    cout << a[i] << " ";
  }
  cout << a[n - 1] << endl;
  cout << cnt << endl;
  return;
}

int main(){
  solve();
  return 0;
}

