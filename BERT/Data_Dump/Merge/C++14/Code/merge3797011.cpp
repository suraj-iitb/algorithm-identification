#define  _USE_MATH_DEFINES
#define  _USE_MATH_DEFINES

#define  rep(i, n) for(int i = 0; i < n; i++)
#define  repx(i, a, n) for(int i = a; i < n; i++)
#define  loop while(1)
#define  lli long long int
#define  aryout(ary) rep(i, ary.size()) cout << ary[i] << (i < ary.size() - 1 ? " " : "\n");
 
#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <utility>
#include <set>

using namespace std;

vector<int> merge(vector<int> v1, vector<int> v2, int &cnt) {

  int v1i = 0, v2i = 0;
  int v1m = v1.size(), v2m = v2.size();

  vector<int> v3;
  while (v1i + v2i < v1m + v2m) {
    if (v1i == v1m) {
      v3.insert(v3.end(), v2.begin() + v2i, v2.end());
      cnt += v2m - v2i;
      break;
    }
    else if (v2i == v2m) {
      v3.insert(v3.end(), v1.begin() + v1i, v1.end());
      cnt += v1m - v1i;
      break;
    }
    else {
      if (v1[v1i] < v2[v2i]) {
        v3.push_back(v1[v1i]);
        v1i += 1;
      }
      else {
        v3.push_back(v2[v2i]);
        v2i += 1;
      }
      cnt += 1;
    }
  }
  return v3;
}

vector<int> merge_sort(vector<int> v, int &cnt) {
  if (v.size() > 1) {
    vector<int> v1, v2;
    int mid = v.size() / 2;
    v1.insert(v1.end(), v.begin(), v.begin() + mid);
    v2.insert(v2.end(), v.begin() + mid, v.end());

    return merge(merge_sort(v1, cnt), merge_sort(v2, cnt), cnt);
  }
  else {
    return v;
  }
}


int main() {

  int n;
  cin >> n;

  vector<int> v(n);
  rep(i, n) cin >> v[i];

  int cnt = 0;
  vector<int> ans = merge_sort(v, cnt);
  aryout(ans);
  cout << cnt << endl;

  return 0;
}

