#include <bits/stdc++.h>
using namespace std;
void printvec(vector<int> vec) {
  int i;
  for (i = 0; i < vec.size() - 1; i++) {
    cout << vec.at(i) << " ";
  }
  cout << vec.at(i) << endl;
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  printvec(a);

  int v, j;
  for (int i = 1; i < n; i++) {
    v = a.at(i);
    j = i - 1;
    while (j >= 0 && a.at(j) > v) {
      a.at(j + 1) = a.at(j);
      j--;
    }
    a.at(j + 1) = v;
    printvec(a);
  }
}
