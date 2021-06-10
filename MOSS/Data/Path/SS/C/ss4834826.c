#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
typedef struct {
    int to;
    ll cost;
}   edge;

vector<vector<edge> > G;
vector<ll> dist;


void djikstra(int s) {
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();    que.pop();
        int u = p.second;
        ll d = p.first;

        if (d > dist[u])
            continue;
        
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].to;   ll c = G[u][i].cost;
            if (dist[v] <= dist[u] + c)
                continue;

            dist[v] = dist[u] + c;
            que.push(P(dist[v], v));
        }
    }
}

int main() {
    int n, m, r;    cin >> n >> m >> r;
    G.resize(n);
    dist.resize(n, 1e15);
    for (int i = 0; i < m; i++) {
        int s, t;   ll c;   cin >> s >> t >> c;
        edge e = {t, c};
        G[s].push_back(e);
    }

    djikstra(r);

    for (int i = 0; i < n; i++) {
        if (dist[i] < 1e15)
            cout << dist[i] << endl;
        else 
            cout << "INF" << endl;
    }

    return 0;
}

