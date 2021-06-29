#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int merge(vi &a, int left, int mid, int right) {
  int n_comp = 0, n1 = mid - left, n2 = right - mid;

  vi l(n1 + 1), r(n2 + 1);
  rep(i, n1) l[i] = a[left + i];
  rep(i, n2) r[i] = a[mid + i];

  l[n1] = INT_MAX;
  r[n2] = INT_MAX;
  
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    n_comp++;
    if (l[i] <= r[j]) {
      a[k] = l[i];
      i++;
    } else {
      a[k] = r[j];
      j++;
    }
  }

  return n_comp;
}

int merge_sort(vi &a, int left, int right) {
  int n_comp = 0;
  if (right > left + 1) {
    int mid = (right + left) / 2;
    n_comp += merge_sort(a, left, mid);
    n_comp += merge_sort(a, mid, right);
    n_comp += merge(a, left, mid, right);
  }

  return n_comp;
}

int main() {
  int n;
  cin >> n;
  vi s(n);
  rep(i, n) cin >> s[i];

  int nc = merge_sort(s, 0, n);

  rep(i, n) {
    cout << s[i];
    i != n - 1 ? cout << " " : cout << endl;
  }

  cout << nc << endl;
}

