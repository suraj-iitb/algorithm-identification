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

int N;
int a[100];

int bubbleSort() {
  int count = 0;
  for(int j = N-1; j >= 1; j--) {
    if(a[j] < a[j-1]) {
      swap(a[j], a[j-1]);
      count++;
    }
  }
  return count;
}

int main() {
  cin >> N;
  rep(i, N) {
    cin >> a[i];
  }
  int ans = 0;
  rep(i, N-1) {
    ans += bubbleSort();
  }
  rep(i, N) {
    cout << a[i];
    if(i != N-1) cout << " ";
    else cout << endl;
  }
  // cout << a[0] << " " << a[1] << endl;
  cout << ans << endl;
  return 0;
}
