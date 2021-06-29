#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
using ll = long long;
using P = pair<int, int>;

tuple<int, vector<int>> bubbleSort(vector<int> a, int n){
  bool flag = true;
  int swaps = 0;
  while (flag) {
    flag = false;
    for (int j=n-1; j>=1; --j) {
      if (a[j] < a[j-1]) {
	int tmp = a[j];
	a[j] = a[j-1];
	a[j-1] = tmp;
	flag = true;
	swaps++;
      }
    }
  }
  return forward_as_tuple(swaps, a);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> ans;
  int times;
  tie(times, ans) = bubbleSort(a, n);
  rep(i, n) printf("%d%c", ans[i], i == n-1 ? '\n':' ');
  cout << times << endl;
  return 0;
}

