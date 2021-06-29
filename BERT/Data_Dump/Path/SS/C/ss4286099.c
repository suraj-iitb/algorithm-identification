#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <cassert>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
// #include <unordered_set>
// #include <unordered_map>
#include <iomanip>
//#pragma GCC optimize("Ofast")  //デバッグ時にoptimized-outされて邪魔だった
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<ll> > vvll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define irep(it, stl) for(auto it = stl.begin(); it != stl.end(); it++)
#define drep(i,n) for(int i = (n) - 1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define mp(p,q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define floatprec(dig) fixed << setprecision(dig)
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int;
#define invar(typ, var) typ var; cin >> var;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
struct io{io(){ios::sync_with_stdio(false);cin.tie(0);}};
const int INF = INT_MAX;
const ll LLINF = 1LL<<60;
const ll MOD = 1000000007;
const double EPS = 1e-9;

struct edge { int from, to, cost; };

signed main(void) {
  cin.tie(0); ios::sync_with_stdio(false);
  
  int V, E, r; cin >> V >> E >> r;
  vector<vector<edge> > points(V, vector<edge>());
  rep(i, E) {
    int s,t,d;
    cin >> s >> t >> d;
    points[s].push_back({s,t,d});
  }
  
  //ダイクストラ
  vector<int> dist(V, INF / 2);
  priority_queue<pii, vector<pii>, greater<pii> > que;
  que.push(mp(0, r));
  dist[r] = 0;
  
  while(!que.empty()) {
    pii p = que.top(); que.pop();
    int d = p.first;
    int v = p.second;
    if(dist[v] < d) continue;
    
    for(edge e : points[v]) {
      if(dist[e.from] + e.cost < dist[e.to]) {
        dist[e.to] = dist[e.from] + e.cost;
        que.push(mp(dist[e.to], e.to));
      }
    }
  }
  
  rep(i, V) {
    if(dist[i] == INF / 2) {
      fin("INF");
    } else {
      fin(dist[i]);
    }
  }
}
