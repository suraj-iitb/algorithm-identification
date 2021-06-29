#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

int main() {
  int N;
  vector<int> a;
  cin >> N;
  rep(i, N) {
    int temp;
    cin >> temp;
    a.push_back(temp);
  }
  rep(i, N) {
    for(int j = i-1; j >= 0; j--) {
      if(a[j+1] < a[j]) {
        swap(a[j+1], a[j]);
      }
    }
    rep(i, N) {
      cout << a[i];
      if(i != N-1) cout << " ";
      else cout << endl;
    }
  }
  return 0;
}
