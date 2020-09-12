#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const int INF = 1000000005;

int cnt = 0;

void merge(vector<int>& s, int left, int mid, int right) {
  int n1 = mid - left, n2 = right - mid;
  vector<int> l(n1 + 1), r(n2 + 1);
  rep(i, n1) l[i] = s[left + i];
  rep(i, n2) r[i] = s[mid + i];
  l[n1] = INF;
  r[n2] = INF;

  int i = 0, j = 0;
  FOR(k, left, right) {
    cnt++;
    if (l[i] <= r[j]) {
      s[k] = l[i];
      i++;
    }
    else {
      s[k] = r[j];
      j++;
    }
  }
}

void mergeSort(vector<int>& s, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(s, left, mid);
    mergeSort(s, mid, right);
    merge(s, left, mid, right);
  }

}

int main() {
  int n;
  cin >> n;
  vector<int> s(n);
  rep(i, n) cin >> s[i];

  mergeSort(s, 0, n);

  rep(i, n) {
    if (i) cout << " ";
    cout << s[i];
  }
  cout << endl;
  cout << cnt << endl;

  
  return 0;
}
