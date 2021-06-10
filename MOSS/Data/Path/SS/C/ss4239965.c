#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'
#define int long long
#define P pair<int,int>

#define INF 1e9
#define MAX_V 100005

struct edge {
    int to;
    int cost;
};

int V,E,r;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;

        for (int i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

signed main() {
    cin >> V >> E >> r;
    for(int i = 0; i < E; i++){
        int a,b,c;
        cin >> a >> b >> c;
        edge e = {b,c};
        G[a].push_back(e);
    }
    dijkstra(r);
    for(int i = 0; i < V; i++){
        if(d[i] == INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
}
