#include <iostream>
#include <vector>
using namespace std;

int n;
int a[500000];
int b[500000];

void merge(int l, int m, int r) {
  for (int i = l; i < r; ++i) {
    b[i] = a[i];
  }
  int p = l;
  int q = m;
  int c = l;
  while (c < r) {
    if (p == m) {
      a[c++] = b[q++];
    } else if (q == r) {
      a[c++] = b[p++];
    } else if (b[p] < b[q]) {
      a[c++] = b[p++];
    } else {
      a[c++] = b[q++];
    }
  }
}

int merge_sort(int l, int r) {
  int t = 0;
  if (l + 1 < r) {
    int m = (l + r) / 2;
    t += merge_sort(l, m);
    t += merge_sort(m, r);
    merge(l, m, r);
    t += r - l;
  }
  return t;
}

int main() {
  cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int t = merge_sort(0, n);
  for (int i = 0; i < n; ++i) {
    if (i) {
      cout << " ";
    }
    cout << a[i];
  }
  cout << endl;
  cout << t << endl;

  return 0;
}

