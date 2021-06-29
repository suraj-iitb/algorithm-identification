#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define drep(i, n) for (int i = (int)(n); i >= 0; i--)

vi counting_sort(vi &a, int k) {
  vi b(a.size()), c(k + 1);

  for (auto i: a) c[i]++;
  for (int i = 1; i <= k; i++) c[i] += c[i - 1];
  
  for (int i = (int)a.size() - 1; i >= 0; i--) {
    b[c[a[i]] - 1] = a[i];
    c[a[i]]--;
  }

  return b;
}

int main() {
  int n, k = 0;
  cin >> n;

  vi a(n);
  rep(i, n) {
    scanf("%d", &a[i]);
    k = max(k, a[i]);
  }

  auto b = counting_sort(a, k);

  rep(i, n)
    printf(i != n - 1 ? "%d " : "%d\n", b[i]);
}

