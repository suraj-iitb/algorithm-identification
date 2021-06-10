#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <utility>
#include <set>
#include <map>
#include <tuple> 
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
using namespace  std;
typedef pair<long long , long long> P;
typedef long long ll;
typedef long long lint;
#define REP(i, n) for(long long (i)=0; (i)<(n); ++i)
#define FOR(i, a, b) for(long long (i)=(a); (i)<(b); ++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
const long long MOD = static_cast<long long>(1e9) + 7LL;
const long long INF = 1234567891234567890LL;

struct Edge{
    ll from;
    ll to;
    ll cost;
    Edge(ll u, ll v, ll c) : from(u), to(v), cost(c){}
};

ostream &operator<<(ostream &s, Edge e){
    s << "<" << e.from << ", " << e.to << ", " << e.cost << " >";
    return s;
}

vector<vector<Edge>> G;
vector<ll> dist;
vector<ll> used;
void init(ll n){
    G.resize(3*n);
    dist.resize(3*n, INF);
    used.resize(3*n, 0);
}

void dijkstra(ll s){
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(0, s));
    while(pq.size()){
        P p = pq.top(); pq.pop();
        ll d = p.first;
        ll v = p.second;
        if(used[v] or d>dist[v]) continue;
        used[v] = 1;
        for(ll i=0; i<G[v].size(); i++){
            Edge edge = G[v][i];
            if(used[edge.to])continue;
            if(dist[edge.to]>dist[v]+edge.cost){
                dist[edge.to] = dist[v]+edge.cost;
                pq.push(P(dist[edge.to], edge.to));
            }
        }
    }
}

signed main(){
    ll N, M;
    ll r;
    cin>>N>>M;
    cin >> r;
    init(N);
    REP(i, M){
        ll u, v, c;
        cin >> u >> v >> c;
        G[u].emplace_back(Edge(u, v, c));
    }
    dist[r] = 0;
    dijkstra(r);
    REP(i, N){
        if(dist[i]!=INF)cout << dist[i] << endl;
        else cout << "INF" << endl;
    } 
    return 0;
}
