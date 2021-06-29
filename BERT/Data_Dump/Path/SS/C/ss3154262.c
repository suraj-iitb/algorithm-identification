#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0,i##_cond=(n);i<i##_cond;++i)
#define FOR(i,a,b) for(ll i=(a),i##_cond=(b);i<i##_cond;++i)
#define ROF(i,a,b) for(ll i=(a)-1,i##_cond=(b);i>=i##_cond;--i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend() //sortで大きい順
#define UNIQUE(v) v.erase(unique(all(v)),v.end())
#define SUM(a) accumulate(all(a),0)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define fst first
#define snd second
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;

const ll inf = 1ll<<62;
const ll mod = 1e9+7;

struct node {
  ll v, d;
  node(ll _a, ll _b):v(_a),d(_b){}
  bool operator<(const node &n) const { return d > n.d; }
};
struct edge {
  ll to, d;
  edge(ll _to, ll _d):to(_to),d(_d){}
};
class dijkstra{
public:
  vector<vector<edge>> G;
  vector<ll> dist;
  vector<ll> prev;

  dijkstra(ll s,const vector<vector<edge>> &_G):G(_G){ // sからの最短経路
    dist.resize(G.size(),1ll << 59);
    //prev.resize(G.size(),-1);
  
    priority_queue<node> que;
    que.push(node(s, 0));
    dist[s] = 0;
    
    while(!que.empty()){
      ll v = que.top().v, d = que.top().d;
      que.pop();
      
      rep(i, G[v].size()){
	ll tmp = d + G[v][i].d;
	if(dist[G[v][i].to] > tmp){
	  dist[G[v][i].to] = tmp;
	  //prev[G[v][i].to] = v;
	  que.push(node(G[v][i].to, tmp));
	}
      }
    }
  }

  vector<ll> getpath(ll t){ // tへの最短経路を返す
    vector<ll> path;
    while(t != -1){
      path.push_back(t);
      t = prev[t];
    }
    reverse(path.begin(), path.end());
    return path;
  }
};

int main(){
#define int ll
  int n,m,r; cin >> n >> m >> r;
  vector<vector<edge>> g(n);
  rep(i,m){
    int s,t,d; cin >> s >> t >> d;
    g[s].pb(edge(t,d));
  }
  dijkstra d(r,g);
  rep(i,n){
    if(d.dist[i] == 1ll<<59) cout << "INF\n";
    else cout << d.dist[i] << endl;
  }
}
