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

class card {
  public:
  char s;
  int n;

  card(char s = '0', int n = 0): s(s), n(n) {}

  bool operator < (const card& c) const {
    return n < c.n;
  }
  bool operator == (const card& c) const {
    return (s == c.s && n == c.n);
  }
  bool operator != (const card& c) const {
    return (s != c.s || n != c.n);
  }
  
};

int partition(vector<card>& t, int p, int r) {
  int x = t[r].n, i = p;
  FOR(j, p, r) {
    if (t[j].n <= x) {
      swap(t[i++], t[j]);
    }
  }
  swap(t[i], t[r]);
  return i;
}

void quicksort(vector<card>& t, int p, int r) {
  if (p < r) {
    int q = partition(t, p, r);
    quicksort(t, p, q-1);
    quicksort(t, q+1, r);
  }
}

int main() {
  int n;
  cin >> n;
  vector<card> t(n), ct(n);
  rep(i, n) {
    cin >> t[i].s >> t[i].n;
    ct[i] = t[i];
  }

  stable_sort(ct.begin(), ct.end());
  quicksort(t, 0, n-1);

  bool same = true;
  rep(i, n) {
    if (t[i] != ct[i]) {
      same = false;
      break;
    }
  }
  if (same) cout << "Stable" << endl;
  else cout << "Not stable" << endl;
  rep(i, n) {
    cout << t[i].s << " " << t[i].n << endl;
  }


  
  return 0;
}

