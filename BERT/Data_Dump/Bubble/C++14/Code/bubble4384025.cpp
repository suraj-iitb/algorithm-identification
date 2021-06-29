#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)n; i++)

using namespace std;
using ll = long long;

template <class iterator>
int bubble_sort(iterator *first, iterator *last) {
  int cnt = 0;
  while (last-- > first) {
    for (iterator *iter = first; iter < last; iter++) {
      if (*iter > *(iter + 1)) {
        auto v = *iter;
        *iter = *(iter + 1);
        *(iter + 1) = v;
        cnt++;
      }
    }
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;

  int A[n];
  rep(i, n) cin >> A[i];

  int cnt;
  cnt = bubble_sort(A, A + n);

  rep(i, n) {
    cout << A[i];
    if (i < n - 1) cout << " ";
  }
  cout << endl;
  cout << cnt << endl;

  return 0;
}

