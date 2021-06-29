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

void selection_sort(vector<int>& vec, const int n) {
  int cnt = 0;
  bool flg = false;
  for(int i = 0; i < n; i++) {
    int minj = i;
    for(int j = i; j < n; j++) {
      if(vec[j] < vec[minj]) {
        minj = j;
        flg = true;
      }
    }
    swap(vec[i], vec[minj]);
    if(flg) { cnt++; flg = false; }
  }

  for(int i = 0; i < n; i++) {
    cout << vec[i];
    if(i != n -1) { cout << " "; }
    else { cout << endl; }
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
  selection_sort(vec, n);
  return 0;
}

