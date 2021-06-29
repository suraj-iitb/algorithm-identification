#include <bits/stdc++.h>
using namespace std;

void hyouji(vector<int> v, int n) {
  for (int k = 0; k < n; k++) {
    if (k == n - 1) {
      cout << v.at(k) << endl;
    } else {
      cout << v.at(k) << " ";
    }
  }
}

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  hyouji(a, n);

  for (int i = 1; i < n; i++) {
    int v = a.at(i);
    int j = i - 1;
    while (j >= 0 && a.at(j) > v) {
      a.at(j + 1) = a.at(j);
      j--;
    }
    a.at(j + 1) = v;
    hyouji(a, n);
  }
}
