#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i ++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PL;
typedef pair<int,int> P;
const ll INF = 1e12;
const ll MOD = 1e9 + 7;

vector<ll> dijkstra(int n, vector<vector<PL>>& G,int& s) {
    vector<ll> dist(n,INF);
    dist[s] = 0;

    priority_queue<PL,vector<PL>,greater<P>> q;
    q.push({0,s});

    while (!q.empty()) {
        PL p = q.top(); q.pop();
        ll d = p.first;
        int v = p.second;
        if (dist[v] < d) continue;
        for (PL p: G[v]) {
            int e = p.first;
            ll cost = p.second;
            if (dist[e] > dist[v] + cost) {
                dist[e] = dist[v] + cost;
                q.push({dist[e],e});
            }
        }  
    }
    return dist;
}

int main() {
    int v,e,r; scanf("%d %d %d",&v,&e,&r);
    vector<vector<PL>> G(v);
    rep(_,e) {
        int a,b,c; scanf("%d %d %d",&a,&b,&c);
        G[a].push_back({b,c});
    }

    vector<ll> dist = dijkstra(v,G,r);
    rep(i,v) {
        if (dist[i] == INF) puts("INF");
        else printf("%ld\n",dist[i]);
    }
}
