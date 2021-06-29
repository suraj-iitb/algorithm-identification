#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_V 100010
const int INF = 1e9;
struct edge { int to, cost; };
typedef pair<int, int> P;

int V, E, r;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push({d[e.to], e.to});
            }
        }
    }
}

int main() {
    cin >> V >> E >> r;
    for (int i = 0; i < E; i++) {
        int s, t, d; cin >> s >> t >> d;
        G[s].push_back({t, d});
    }

    dijkstra(r);
    for (int i = 0; i < V; i++) {
        if (d[i] == INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
}
