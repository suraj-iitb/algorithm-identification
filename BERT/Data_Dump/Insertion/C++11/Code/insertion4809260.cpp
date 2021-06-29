#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) (int)(x).size()

void printList (const vector<int>& v) {
  for (int i = 0; i < sz(v); i++) {
    cout << v[i] << (i == sz(v) - 1 ? '\n' : ' ');
  }
}

void insertionSort (vector<int>& a) {
  int n = sz(a);
  for (int i = 0; i < n; i++) {
    int x = a[i], j = i - 1;
    while (j >= 0 && a[j] > x) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = x;
    printList(a);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  insertionSort(a);
}


