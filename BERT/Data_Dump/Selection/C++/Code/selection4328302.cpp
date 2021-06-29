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
  for(int i = 0; i < n; i++){
    int minj = i;
    for(int j = i + 1; j < n; j++){
      if(a[j] < a[minj]){
        minj = j;
      }
    }
    if(minj == i) continue;
    cnt++;
    int t = a[i];
    a[i] = a[minj];
    a[minj] = t;
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

