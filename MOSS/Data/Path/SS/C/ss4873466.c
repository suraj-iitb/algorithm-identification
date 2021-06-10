#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iomanip>
using namespace std;
typedef long long ll;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define EPS (1e-7)
#define INF (1e15)
#define PI (acos(-1))
#define MOD 1000000007

#define REP(i,n) for(int i=0;i<n;i++)
#define REPS(i,f,n) for(int i=(f);i<(n);i++)
#define EACH(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define arrdump(n,a) for(int i=0;i<n;i++) {cout<<((i>0)? " ":"")<<a[i];}cout<<"\n";


typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy4[]={0, 0, 1, -1};
int dx4[]={1, -1, 0, 0};
int dx8[]={0, 0, 1, -1, 1, 1, -1, -1};
int dy8[]={1, -1, 0, 0, 1, -1, -1, 1};

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja

struct edge{int to, cost;};
vector<edge> G[100005];
ll dist[1000005];

int V, E;
int r;

void dij() {
  min_priority_queue<P> que;
  fill(dist, dist + V, INF);
  dist[r] = 0;
  que.push({0, r});

  while (!que.empty()) {
    P p = que.top(); que.pop();
    int v = p.second;
    if (dist[v] < p.first) continue;
    for (edge e : G[v]) {
      if (dist[e.to] > dist[v] + e.cost) {
        dist[e.to] = dist[v] + e.cost;
        que.push({dist[e.to], e.to});
      }
    }
  }
}

int main() {
  cin >> V >> E >> r;
  REP(i, E) {
    int s, t, d; cin >> s >> t >> d;
    G[s].push_back({t, d});
  }

  dij();
  for (int i = 0; i < V; i++) {
    if (dist[i] == INF) {
      cout << "INF" << "\n";
    } else {
      cout << dist[i] << "\n";
    }
  }

  return 0;
}

