#include <bits/stdc++.h>
using namespace std;

void printvec(vector<int>);

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  int c = 0;
  for (int i = 0; i < n; i++) {
    int minj = i;
    for (int j = i; j < n; j++) {
      if (a.at(j) < a.at(minj)) {
        minj = j;
      }
    }
    if (i != minj) {
      swap(a.at(i), a.at(minj));
      c++;
    }
  }
  printvec(a);
  cout << c << endl;
}

void printvec(vector<int> vec) {
  for (int i = 0; i < vec.size(); i++) {
    if (i) cout << " ";
    cout << vec.at(i);
  }
  cout << endl;
}
