#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i < (int)n; i++)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void insertion_sort(int* a, int n) {
  int v, j;
  for(int i=1; i < n; i++) {
    rep(i, n) {
      cout << a[i];
      if(i != n-1) cout << " ";
    }
    cout << endl;
    v = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > v) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
  }
  rep(i, n) {
    cout << a[i];
    if(i != n-1) cout << " ";
  }
  cout << endl;
}

int main(void) {
  int n;
  cin >> n;

  int A[n];
  rep(i, n) cin >> A[i];

  insertion_sort(A, n);
}

