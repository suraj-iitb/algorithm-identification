#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << (x) << '\n';
typedef int64_t Int;
Int mod = 1e9+7;
Int INF = 1e9+7;

#define MAX_V 100005

struct edge { int to, cost; };
typedef pair<Int, Int> P;

vector<edge> G[MAX_V];
vector<Int> d(MAX_V);

void dijkstra(Int s) {
    priority_queue<P, vector<P>, greater<P>> q;
    fill(d.begin(), d.end(), INF);
    d[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        P p = q.top();
        q.pop();
        Int v = p.second;
        if (d[v] < p.first) continue;
        for (Int i = 0; i < (Int)G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                q.push({d[e.to], e.to});
            }
        }
    }
}

int main() {
    Int V, E, r;
    cin >> V >> E >> r;
    for (Int i = 0; i < E; i++) {
        Int a;
        edge b;
        cin >> a >> b.to >> b.cost;
        G[a].emplace_back(b);
    }
    dijkstra(r);
    for (Int i = 0; i < V; i++) {
        if (d[i] != INF) {
            dump(d[i]);
        }
        else {
            dump("INF");
        }
    }
    return 0;
}
