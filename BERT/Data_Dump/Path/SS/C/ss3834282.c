#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, P> P3;
typedef pair<P, P> PP;
constexpr ll MOD = ll(1e9 + 7);
constexpr int IINF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
constexpr int MAX_N = int(1e5) + 5;
constexpr double EPS = 1e-9;
constexpr int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i > 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), (v).end()

int main() {
    int V, E, root;
    cin >> V >> E >> root;
    vector<vector<P> > g(V);
    for(int i=0;i<E;i++){
        int s, t, d;
        cin >> s >> t >> d;
        g[s].push_back({t, d});
    }
    vector<ll> dist(V, IINF);
    dist[root] = 0;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push({0,root});
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(dist[v] < p.first) continue;
        for(auto e : g[v]){
            ll u = e.first, d = e.second;
            if(dist[u] > dist[v] + d){
                dist[u] = dist[v] + d;
                que.push({dist[u], u});
            }
        }
    }
    for(int i=0;i<V;i++){
        if(dist[i] < IINF){
            cout << dist[i] << endl;
        }
        else{
            cout << "INF" << endl;
        }
    }
    return 0;
}

