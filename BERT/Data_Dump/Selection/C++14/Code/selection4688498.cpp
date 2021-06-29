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

int selectionSort() {
  int count = 0;
  rep(i, N) {
    // int key = a[i];
    int ind = i;
    for(int j = i+1; j < N; j++) {
      if(a[j] < a[ind]) {
        ind = j;
      }
    }
    if(ind != i) {
      swap(a[i], a[ind]);
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
  int ans = selectionSort();
  rep(i, N) {
    cout << a[i];
    if(i != N-1) cout << " ";
    else cout << endl;
  }
  cout << ans << endl;
  return 0;
}
