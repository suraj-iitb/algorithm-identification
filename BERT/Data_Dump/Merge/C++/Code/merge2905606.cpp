#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define pb push_back
#define rep(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < (n); i++)
#define mod (ll)(1e9+7)
#define int ll

#define MAX 500000
#define SENTINEL 2000000000

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

ll L[MAX/2+2], R[MAX/2+2], cnt;

void merge(int a[], int n, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  rep(i, n1) L[i] = a[left + i];
  rep(i, n2) R[i] = a[mid + i];
  L[n1] = R[n2] = SENTINEL;
  int i = 0, j = 0;

  for(int k = left; k < right; k++) {
    cnt++;
    if(L[i] <= R[j]) a[k] = L[i++];
    else a[k] = R[j++];
  }
}

void mergeSort(int a[], int n, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(a, n, left, mid);
    mergeSort(a, n, mid, right);
    merge(a, n, left, mid, right);
  }
}

signed main() {
	ll a[MAX], n;
  cnt = 0;
  cin >> n;
  rep(i, n) cin >> a[i];

  mergeSort(a, n, 0, n);
  rep(i, n) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;

  cout << cnt << endl;
}
