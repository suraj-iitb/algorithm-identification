#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
const double PI = acos(-1.0);
#define MOD 1000000007LL
#define endl "\n"

struct edge{
  ll from, to, cost;
  edge(){}
  edge(ll t, ll c){ to = t; cost = c;}
  edge(ll f, ll t, ll c){ from = f; to = t; cost = c;}
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, r;
  cin >> N >> M >> r;
  vector<vector<edge>> G(N, vector<edge>(0));
  while(M--){
    int s, t, d;
    cin >> s >> t >> d;
    G.at(s).push_back(edge(t, d));
  }
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, r));
  vi ans(N, INT_INF);
  while(!que.empty()){
    int v = que.top().second;
    int c = que.top().first;
    que.pop();
    if(ans.at(v) < c) continue;
    ans.at(v) = c;
    for(int i = 0; i < sz(G.at(v)); i++){
      int next = G.at(v).at(i).to;
      int cost = G.at(v).at(i).cost;
      que.push(P(c+cost, next));
    }
  }
  for(auto x: ans){
    if(x == INT_INF) cout << "INF" << endl;
    else cout << x << endl;
  }
}
