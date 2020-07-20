#include <bits/stdc++.h>
using namespace std;

void printvec(vector<int> vec) {
  for (int i = 0; i < vec.size(); i++) {
    if (i) cout << " ";
    cout << vec.at(i);
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  bool flag = true;
  int c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      if (a.at(j) < a.at(j - 1)) {
        swap(a.at(j), a.at(j - 1));
        c++;
      }
    }
  }
  printvec(a);
  cout << c << endl;
}
