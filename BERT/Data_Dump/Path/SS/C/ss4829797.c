#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define P pair<int, int>
#define Pl pair<ll, ll>
#define dvec vector<vector<ll>>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;

struct edge
{
  int to;
  ll cost;
};

void dijk(const vector<vector<edge>> &G, int s, vector<ll> &dist)
{
  auto f = [](edge a, edge b){
    return a.cost > b.cost;};
  priority_queue<edge, vector<edge>, decltype(f)> pq(f);
  edge first; first.to = s, first.cost = dist[s];
  pq.emplace(first);
  while(!pq.empty()){
    edge p = pq.top();
    pq.pop();
    int v = p.to;
    if(dist[v] < p.cost) continue;
    for(auto e: G[v]){
      if(dist[e.to] > dist[v] + e.cost) {
        dist[e.to] = dist[v] + e.cost;
        edge tmp; tmp.to = e.to, tmp.cost = dist[e.to];
        pq.emplace(tmp);
      }
    }
  }
}

int main()
{
  int V, E; cin >> V >> E;
  int S; cin >> S;
  vector<vector<edge>> G(V);
  rep(i, 0, E){
    int s, t, d; cin >> s >> t >> d;
    edge tmp = {t, d};
    G[s].push_back(tmp);
  }
  vector<ll> dist(V, INF);
  dist[S] = 0;

  dijk(G, S, dist);

  rep(i, 0, V){
    if(dist[i] != INF) cout << dist[i] << endl;
    else cout << "INF" << endl;
  }
}

