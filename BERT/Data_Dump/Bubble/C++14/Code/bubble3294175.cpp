#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cassert>
using namespace std;

void bubble_sort(vector<int>& vec, int n) {
  bool flg = true;
  int i = 0;
  int cnt = 0;
  while(flg) {
    flg = false;
    for(int j = n - 1; j > i; j--) {
      if(vec[j] < vec[j - 1]) {
        swap(vec[j], vec[j - 1]);
        flg = true;
        cnt++;
      }
    }
    i++;
  }

  for(int k = 0; k < n; k++) {
    cout << vec[k];
    if(k != n - 1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
  cout << cnt << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for(auto& v : vec) {
    cin >> v;
  }
  bubble_sort(vec, n);
  return 0;
}

