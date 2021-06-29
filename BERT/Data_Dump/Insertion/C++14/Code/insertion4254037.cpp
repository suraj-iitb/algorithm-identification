#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const string ln = "\n";
constexpr int INF = 1001001001;
constexpr int MOD = 1000000007;

void insertionSort(vector<int>& A, int n) {
  for (int k = 0; k < n; k++) {
    cout << A[k] << (k == n - 1 ? ln : " ");
  }
  
  for (int i = 1; i < n; i++) {
    int v = A[i];
    int j = i - 1;

    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;

    for (int k = 0; k < n; k++) {
      cout << A[k] << (k == n - 1 ? ln : " ");
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  insertionSort(a, n);

  return 0;
}
