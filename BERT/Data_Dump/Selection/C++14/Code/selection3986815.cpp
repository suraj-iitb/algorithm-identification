#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;

int main() {
  int n,count = 0;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  rep(i,a.size()) {
    int mini = i;
    for(int j = i; j < a.size(); j++) {
      if(a[j] < a[mini]) {
        mini = j;
      }
    }
    swap(a[i],a[mini]);
    if(a[i] != a[mini]) {
      count++;
    }
  }

  rep(i,n) {
    if(i != n-1) {
      cout << a[i] << ' ';
    }else {
      cout << a[i] << endl;
    }
  }
  cout << count << endl;
  return 0;
}
