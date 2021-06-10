#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;
const int MOD = 1000000007;
const double pi = acos(-1);
ll gcd(ll a, ll b) {if(b == 0) return a; else return gcd(b,a%b);}
ll lcm(ll a, ll b) {return a*b/gcd(a,b);}

struct edge{
    int to;
    ll c;
};

void dijkstra(int s, vector<vector<edge>> &G, vecl &dist) {
    dist[s] = 0;
    priority_queue<P,vector<P>,greater<P>> q;
    q.push({0,s});

    while(!q.empty()) {
        P p = q.top();
        q.pop();

        int v = p.second;
        ll d = p.first;

        if(dist[v] < d) continue;

        for(auto e : G[v]) {
            if(dist[e.to] > dist[v] + e.c) {
                dist[e.to] = dist[v] + e.c;
                q.push({dist[e.to],e.to});
            }
        }
    }
    
}

ll INF = 1LL<<60;

int main() {
    int V,E; cin >> V >> E;
    int r; cin >> r;
    vector<vector<edge>> G(V);
    vecl dist(V,INF);
    REP(i,E) {
        int a,b,c; cin >> a>> b >> c;
        G[a].push_back({b,c});
    }
    dijkstra(r,G,dist);

    REP(i,V) {
        if(dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
    return 0;
}
