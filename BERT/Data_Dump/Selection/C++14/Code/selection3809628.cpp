/**
 *      purpose : 
 *      author  : kyomukyomupurin
 *      created : 
**/

// input/output
#include <fstream>
#include <iostream>
#include <sstream>
// container class
#include <array>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// math, algorithm
#include <algorithm>
#include <cmath>
#include <complex>
#include <numeric>
// etc
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstring>
#include <chrono>
#include <iomanip>
#include <random>
#include <utility>
// using-directive
using namespace std;
// alias template
using int64 = long long;
using vi = vector<int>;
using vl = vector<int64>;
using pii = pair<int, int>;
using pii = pair<int, int>;
using pll = pair<int64, int64>;
// text macro replacement
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define print(x) cout << (x) << '\n'
#define debug(x) cerr << #x << ": " << (x) << '\n'
#define dbg(v) for (size_t _ = 0; _ < v.size(); ++_){cerr << #v << "[" << _ << "] : " << v[_] << '\n';}
// variadic template
template<typename T> inline void chmin(T &a, T b) {if (a > b) a = b; return;}
template<typename T> inline void chmax(T &a, T b) {if (a < b) a = b; return;}
// constant
const int INF = (1<<30) - 1;
const int64 INF64 = (1LL<<62) - 1;
const int MOD = 1000000007;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int cnt = 0;

  for (int i = 0; i < n; ++i) {
    int mn = i;
    for (int j = i; j < n; ++j) {
      if (a[j] < a[mn]) {
        mn = j;
      }
    }
    cnt += i != mn;
    swap(a[i], a[mn]);
  }
  
  for (int i = 0; i < n; ++i) {
    cout << a[i];
    if (i != n - 1) cout << " ";
    else cout << '\n';
  }
  cout << cnt << '\n';

  return 0;
}
