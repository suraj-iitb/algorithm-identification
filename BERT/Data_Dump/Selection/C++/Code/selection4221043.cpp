#include <bits/stdc++.h>
using namespace std;
#define all(v) begin(v), end(v)
#define allg(v) begin(v), end(v), greater<int>()

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    int minj = i;
    for(int j = i; j < n; j++) {
      if (a.at(j) < a.at(minj))
        minj = j;
    }
    swap(a.at(i), a.at(minj));
    if(i != minj) cnt++;
  }
  
  for(int i = 0; i < n-1; i++)
    cout << a.at(i) << " ";
  cout << a.at(n-1) << "\n";
  cout << cnt << "\n";

}


