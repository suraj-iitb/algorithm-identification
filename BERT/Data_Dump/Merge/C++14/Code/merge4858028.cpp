#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using Graph = vector<vector<int>>;
// using P = pair<ll, ll>;
const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0, 0, -1};
const ll mod = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

#define MAX 500000
int A[MAX];
int n, sum = 0;

void merge(int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1 + 1], R[n2 + 1];
  rep(i, n1) L[i] = A[left + i];
  rep(i, n2) R[i] = A[mid + i];
  L[n1] = INF;
  R[n2] = INF;
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    sum++;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
  /* rep(i, n1) cout << L[i] << " ";
  cout << " ";
  rep(i, n2) cout << R[i] << " ";
  cout << endl; */
}

void mergeSort(int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////
  cin >> n;
  rep(i, n) cin >> A[i];
  mergeSort(0, n);
  rep(i, n - 1) cout << A[i] << " ";
  cout << A[n - 1] << endl;
  cout << sum << endl;
  return 0;
}

