#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
using ll = long long;
using P = pair<int, int>;

int cnt = 0;
const int INF = 1001001001;
//int l[500005/2+2], r[500005/2+2];

void merge(vector<int> &a, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  vector<int> l(n1+1), r(n2+1);
  rep(i, n1) {
    l[i] = a[left + i];
  }
  rep(i, n2) {
    r[i] = a[mid+i];
  }
  l[n1] = INF;
  r[n2] = INF;
  int i = 0;
  int j = 0;
  for (int k=left; k<right; ++k) {
    cnt++;
    if (l[i] <= r[j]) {
      a[k] = l[i];
      i++;
    } else {
      a[k] = r[j];
      j++;
    }
  }
}

void mergeSort(vector<int> &a, int left, int right) {
  if (left+1 < right) {
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid ,right);
    merge(a, left, mid, right);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> s(n);
  rep(i,n) cin >> s[i];

  mergeSort(s, 0, n);
  rep(i,n) {
    printf("%d%c", s[i], (i == n-1 ? '\n':' '));
  }
  cout << cnt << endl;
  return 0;
}

