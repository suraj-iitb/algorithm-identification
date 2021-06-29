#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, cnt, tmp;
  bool flag = true;
  string s;
  vector<int> v;
  cin >> n;
  cin.ignore();
  getline(cin, s);
  stringstream ss(s);
  while (ss >> tmp)
    v.push_back(tmp);

  cnt = 0;

  while (flag) {
    flag = false;
    for (int i = n - 1; i > 0; i--) {
      if (v[i] < v[i - 1]) {
        tmp = v[i];
        v[i] = v[i - 1];
        v[i - 1] = tmp;
        cnt++;
        flag = true;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (i == n - 1)
      cout << v[i] << endl;
    else
      cout << v[i] << ' ';
  }

  cout << cnt << endl;

  return 0;
}

