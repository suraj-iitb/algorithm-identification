#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct C {
  public:
    string s;
    int n;
    int p;

    C(string s, int n, int p) : s(s), n(n), p(p) {};

    bool operator<(const C &c) const {
      if (this->n < c.n) {
        return true;
      }
      return false;
    }
};

template<typename T>
int partition(vector<T> &a, int p, int r) {
  T x = a[r - 1];
  int i = p;
  for (int j = p; j < r - 1; ++j) {
    if (!(x < a[j])) {
      T t = a[i];
      a[i] = a[j];
      a[j] = t;
      ++i;
    }
  }
  T t = a[i];
  a[i] = a[r - 1];
  a[r - 1] = t;
  return i;
}

template<typename T>
void quick_sort(vector<T> &a, int p, int r) {
  if (p < r - 1) {
    int q = partition(a, p, r);
    quick_sort(a, p, q);
    quick_sort(a, q + 1, r);
  }
}

int main() {
  cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<C> a;
  for (int i = 0; i < n; ++i) {
    string s;
    int t;
    cin >> s >> t;
    a.push_back(C(s, t, i));
  }

  quick_sort(a, 0, n);
  bool stable = true;
  for (int i = 0; i < n - 1; ++i) {
    if (a[i].n != a[i + 1].n) {
      continue;
    }
    if (a[i].p > a[i + 1].p) {
      stable = false;
    }
  }

  cout << (stable ? "Stable" : "Not stable") << endl;
  for (int i = 0; i < n; ++i) {
    cout << a[i].s << " " << a[i].n << endl;
  }

  return 0;
}

