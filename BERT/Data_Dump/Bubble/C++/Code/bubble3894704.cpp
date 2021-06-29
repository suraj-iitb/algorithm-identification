#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;

int counter = 0;

void ans(vector<int>& a, int n) {
  rep(i, n-1) cout << a[i] <<  " ";
  cout << a[n-1] << endl;
}

void bubbleSort(vector<int>& a, int n) {
  int flag = 1;
  while (flag) {
    flag = 0;
    FORR(j, n-1, 1) {
      if (a[j] < a[j-1]) {
        swap(a[j], a[j-1]);
        flag = 1;
        counter++;
      }
    }
  }
  ans(a, n);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  bubbleSort(a, n);
  cout << counter << endl;
  return 0;
}
