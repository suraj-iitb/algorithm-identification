#include <bits/stdc++.h>
using namespace std;

int bubbleSort(vector<int> &v) {
  int tot = 0;
  for (int i = 0, n = v.size(); i < n; i++) {
    int k = i;
    for (int j = i; j < n; j++) {
      if (v[j] < v[k]) {
        k = j;
      }
    }
    if (k != i) {
      ++tot;
      swap(v[k], v[i]);
    }
  }
  return tot;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v) cin >> i;
  int t = bubbleSort(v);
  cout << v[0];
  for (int i = 1; i < n; i++) cout << " " << v[i];
  cout << endl << t << endl;
  return 0;
}

