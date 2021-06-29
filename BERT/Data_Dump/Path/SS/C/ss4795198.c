#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<ld> vld;
typedef vector<string> vstr;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;  // 小さい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;     // 大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define endl "\n"

ll MOD = 1000000007;
ll INF = 1e18;
ld EPS = 1e-9;
ld PI = M_PI;
vll dx = {1, 0, -1, 0, 1, -1, -1, 1};
vll dy = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}     //最小公倍数

void yes(){ cout << "YES" << endl;}
void no(){ cout << "NO" << endl;}

//-----------------------------------------

class edge{
  public:
    ll to;
    ll cost;
};

ll n; // 頂点数
vector<vector<edge>> G;
vector<ll> dist;
vector<ll> pre;
vector<ll> par;

void init(){
  G.resize(n);
  dist.resize(n);
  pre.resize(n);
  par.resize(n);
}

// 頂点sからの最短路
void dijkstra(ll s){
  priority_queue<pll, vector<pll>, greater<pll>> que;

  for(ll i = 0; i < n; i++){
    dist[i] = INF; par[i] = i;
  }

  dist[s] = 0;
  que.push({0,s});

  while(!que.empty()){
    pll p = que.top(); que.pop();
    ll v = p.second;
    if(dist[v] < p.first) continue;
    for(ll i = 0; i < G[v].size(); i++){
      edge e = G[v][i];
      if(dist[e.to] > dist[v] + e.cost){
        dist[e.to] = dist[v] + e.cost;
        par[e.to] = v;
        que.push({dist[e.to], e.to});
      }
    }
  }

}

// tへの最短路
vll get_path(ll t){
  vll res;
  ll i = t;
  while(i != par[i]){
    res.push_back(i);
    i = par[i];
  }
  reverse(ALL(res));
  return res;
}



//-----------------------------------------
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  cin >> n;
  init();
  ll e, s;
  cin >> e >> s;
  REP(i,e){
    ll f, t, c;
    cin >> f >> t >> c;
    G[f].push_back({t,c});
  }

  dijkstra(s);

  REP(i,n){
    if(dist[i] == INF) cout << "INF" << endl;
    else cout << dist[i] << endl;
  }


  

  return 0;
}


