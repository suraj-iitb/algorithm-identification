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


  bool flag = true;
  int cnt = 0;
  while (flag) {
    flag = false;
    for (int i=n-1; i>0; i--) {
      if (a[i] < a[i-1]) {
        swap(a[i], a[i-1]);
        flag = true;
        cnt++;
      }
    }
  }
  printVector(a, " ");
  cout << cnt << endl;
}

