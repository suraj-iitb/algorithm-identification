#include <bits/stdc++.h>
using namespace std;
#define INF 100000000000000007
#define int long long
typedef pair<int, int> P;

const int MAX_V = 1000010;

struct edge {
    int to, cost;
};

int V, E, start;
vector<edge> g[MAX_V];
int d[MAX_V];

void dijikstra(int s) {
    fill(d, d + V, INF);
    d[s] = 0;
    priority_queue< P, vector<P>, greater<P> > que;
    que.push(P(0, s));

    while(que.size()) {
        P p = que.top(); // cost, to
        que.pop();

        int v = p.second; // to
        if(d[v] < p.first) continue;

        for(int i = 0; i < g[v].size(); i++) {
            edge e = g[v][i];
            if(d[v] + e.cost < d[e.to]) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

signed main() {
    cin >> V >> E >> start; // 頂点数, 辺数, 起点
    for(int i = 0; i < E; i++) {
        int s;
        edge e;
        cin >> s >> e.to >> e.cost;
        g[s].push_back(e);
    }

    dijikstra(start);

    for(int i = 0; i < V; i++) {
        //cout << i << ": ";
        if(d[i] != INF) cout << d[i] << endl;
        else cout << "INF" << endl;
    }
}
