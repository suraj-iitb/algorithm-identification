#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define fi first
#define se second
#define v(T) vector<T>
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
const long double PI = acos(-1.0);
const ll mod = 1e9+7;
//const ll mod = 998244353;
const int INF = 1e9+50;
const ll INFL = 1e15;
const int di[] = {1,0,-1,0};
const int dj[] = {0,1,0,-1};
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,v.size())i>>v[j];return i;}
template<typename T>ostream& operator<<(ostream&o,const v(T)&v){rep(j,v.size())o<<v[j]<<endl;return o;}
ll max(ll a, ll b) {if(a < b) return b; else return a;}
ll min(ll a, ll b) {if(a > b) return b; else return a;}
ll gcd(ll a, ll b) {if(a == 0 || b == 0) return max(a,b); else if(a%b==0)return b;else return gcd(b,a%b);}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
void chmax(ll &a, ll b) {if(a < b) a = b;}
void chmin(ll &a, ll b) {if(a > b) a = b;}
vvl prod(const vvl& a, vvl& b) {
  assert(a[0].size() == b.size());
  vvl ret(a.size(), vl(b[0].size()));
  rep(i,a.size()) rep(j,b[0].size()) rep(k,a[0].size()) {
    ret[i][j] += a[i][k] * b[k][j];
  }
  return ret;
}






int n;
vector<vector<P> > m;

void dijkstra(int r) {
  priority_queue<P, vector<P>, greater<P> > pq;
  vi d(n,INF), vis(n,0);
  pq.push(P(0,r));
  d[r] = 0;
  while(pq.size()) {
    P f = pq.top(); pq.pop();
    int u = f.se;
    vis[u] = 1;
    if(d[u] < f.fi) continue;
    rep(i,m[u].size()) {
      int v = m[u][i].fi;
      if(vis[v]) continue;
      if(d[u] + m[u][i].se < d[v]) {
        d[v] = d[u] + m[u][i].se;
        pq.push(P(d[v],v));
      }
    }
  }
  rep(i,n) {
    if(d[i] == INF) cout << "INF" << endl;
    else cout << d[i] << endl;
  }
}

int main() {
  int e,r;
  cin >> n >> e >> r;
  m.resize(n);
  rep(i,e) {
    int s,t,d; cin >> s >> t >> d;
    m[s].pb(P(t,d));
  }
  dijkstra(r);
}


