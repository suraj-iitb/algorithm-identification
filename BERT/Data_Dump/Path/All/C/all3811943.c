

/**
 *      purpose : 
 *      author  : kyomukyomupurin
 *      created : 
**/

// input/output
#include <iostream>
#include <fstream>
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

int64 dis[101][101];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int V, E; cin >> V >> E;
  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
      if (i == j) {
        dis[i][j] = 0;
      } else {
        dis[i][j] = INF64;
      }
    }
  }

  for (int i = 0; i < E; ++i) {
    int s, t, d; cin >> s >> t >> d;
    dis[s][t] = (int64)d;
  }

  for (int k = 0; k < V; ++k) {
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        if (dis[i][k] == INF64 || dis[k][j] == INF64) continue;
        chmin(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }

  for (int i = 0; i < V; ++i) {
    if (dis[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << '\n';
      return 0;
    }
  }

  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
      if (dis[i][j] == INF64) {
        cout << "INF";
      } else {
        cout << dis[i][j];
      }
      if (j != V - 1) cout << " ";
    }
    cout << '\n';
  }

  return 0;
}
