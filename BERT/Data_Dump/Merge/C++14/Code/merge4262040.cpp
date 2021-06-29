#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cnt;

void merge(vector<ll> &A, ll left, ll mid, ll right) {
  ll lm = mid - left, mr = right - mid;
  vector<ll> LM(lm + 1, 1e10);
  vector<ll> MR(mr + 1, 1e10);
  for (ll i = 0; i < lm; i++) {
    LM[i] = A[left + i];
  }
  for (ll i = 0; i < mr; i++) {
    MR[i] = A[mid + i];
  }

  ll l = 0, r = 0;
  for (ll i = left; i < right; i++) {
    cnt++;
    if (LM[l] <= MR[r]) {
      A[i] = LM[l]; l++;
    } else {
      A[i] = MR[r]; r++;
    }
  }
}

void mergeSort(vector<ll> &A, ll left, ll right) {
  if (left + 1 < right) {
    ll mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cnt = 0;
  ll N; cin >> N;
  vector<ll> A(N); for (ll i = 0; i < N; i++) cin >> A[i];
  mergeSort(A, 0, N);

  cout << A[0]; for (int i = 1; i < A.size(); i++) { cout << ' ' << A[i]; }
  cout << '\n' << cnt << '\n';
  return 0;
}
