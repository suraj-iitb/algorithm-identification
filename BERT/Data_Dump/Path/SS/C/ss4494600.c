#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const int MAX = 510000;
const int MOD = 1000000007;

struct Edge {
    ll to;
    ll cost;
    Edge(ll t, ll w) : to(t), cost(w) { }
};

ll V, d[MAX];
vector<Edge> G[MAX]; // 隣接リスト表現

void dijkstra(ll s) {
    fill(d, d + V, INF);
    d[s] = 0;  // 始点sへの最短距離は0

    priority_queue<P, vector<P>, greater<P> > que;  // 距離が小さい順に取り出せるようgreater<P>を指定
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        ll v = p.second;  // 更新した頂点の中で距離が最小の頂点v
        if (d[v] < p.first) {
            continue;
        }
        for (auto e : G[v]) {  // 頂点vから出る辺eを走査
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}


int main(){
  ll M; cin >> V >> M;
  ll r; cin >> r;
  rep(i,M){
    ll a, b, c; cin >> a >> b >> c;
    G[a].pb(Edge(b,c));
  }
  dijkstra(r);
  rep(i,V){
    if(d[i] == INF) cout << "INF" << endl;
    else cout << d[i] << endl;
  }


}

