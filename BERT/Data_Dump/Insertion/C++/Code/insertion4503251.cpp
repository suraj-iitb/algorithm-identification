#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++) { //a(n)の生成
    cin >> a.at(i);
  }

   for (int k = 0; k < n; k++) { //display
      cout << a.at(k);
      if (k != n-1)
      cout << " ";
    }
    cout << endl;

  for (int i = 1; i < n; i++) {
    int v = a.at(i);
    int j = i - 1;
    while (j >= 0 && a.at(j) > v) {
      a.at(j+1) = a.at(j);
      j--;
      a.at(j+1) = v;
    }

    for (int k = 0; k < n; k++) { //display
      cout << a.at(k);
      if (k != n-1)
      cout << " ";
    }
    cout << endl;
  }

}
