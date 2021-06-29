#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, cnt, tmp, minj;
  bool flag = false;
  string s;
  vector<int> v;
  cin >> n;
  cin.ignore();
  getline(cin, s);
  stringstream ss(s);
  while (ss >> tmp)
    v.push_back(tmp);

  cnt = 0;

  for (int i = 0; i < n; i++) {
    minj = i;
    for (int j = i; j < n; j++) {
      if (v[j] < v[minj]) {
        minj = j;
        flag = true;
      }
    }
    if (flag) {
      tmp = v[i];
      v[i] = v[minj];
      v[minj] = tmp;
      cnt++;
      flag = false;
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

