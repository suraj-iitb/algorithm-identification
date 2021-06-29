#include <bits/stdc++.h>
using namespace std;

//printVector(配列, 区切り文字)
template <typename T>
void printVector(vector<T> v, string delimiter) {
  for (int i=0; i<v.size(); i++) {
    if (i>0) cout << delimiter;
    cout << v[i];
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  int minj;
  int cnt = 0;
  for (int i=0; i<n; i++) {
    minj = i;
    for (int j=i; j<n; j++) {
      if (a[j] < a[minj]) {
        minj = j;
      }
    }
    if (minj != i) {
      swap(a[i], a[minj]);
      cnt++;
    }
  }

  printVector(a, " ");
  cout << cnt << endl;
}

