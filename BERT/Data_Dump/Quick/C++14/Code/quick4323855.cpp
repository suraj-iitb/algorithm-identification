#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vpci = vector<pair<char, int>>;
using miq = unordered_map<int, queue<char>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int partition(vpci &a, int p, int r) {
  int x = a[r].second, i = p - 1;
  
  for (int j = p; j < r; j++) {
    if (a[j].second <= x) {
      i++;
      swap(a[i], a[j]);
    }
  }
  
  i++;
  swap(a[i], a[r]);

  return i;
}

void quick_sort(vpci &a, int p, int r) {
  if (p < r) {
    int q = partition(a, p, r);
    quick_sort(a, p, q - 1);
    quick_sort(a, q + 1, r);
  }
}

bool is_stable(miq m, vpci a) {
  for (auto p: a) {
    auto &q = m[p.second];
    if (q.front() != p.first) return false;
    q.pop();
  }

  return true;
}

int main() {
  int n;
  cin >> n;
  
  vpci vp;
  miq m;
  rep(i, n) {
    char c;
    int x;
    cin >> c >> x;
    vp.push_back(make_pair(c, x));

    if (!m.count(x)) m[x] = queue<char>();
    m[x].push(c);
  }

  quick_sort(vp, 0, n - 1);
  
  cout << (is_stable(m, vp) ? "Stable" : "Not stable") << endl; 

  for (auto p: vp) printf("%c %d\n", p.first, p.second);
}

