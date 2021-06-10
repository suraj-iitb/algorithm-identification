#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const int INF = 1 << 30;
struct edge { 
    int to, cost;
    //edge(int to, int cost): to(to), cost(cost) {}    
};
typedef pair<int, int> P;

int V, E, r;
vector<int> s(1 << 20), t(1 << 20), d(1 << 20);
vector<edge> G[1 << 20];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P>> Q;
    for (int i = 0; i < V; i++) d[i] = INF;
    d[s] = 0;
    Q.push(P(0, s));

    while (!Q.empty()) {
        P p = Q.top(); Q.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (edge e : G[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                Q.push(P(d[e.to], e.to));
            }
        }
    }
    return;
}

int main() {
    cin >> V >> E >> r;
    for (int i = 0; i < E; i++) {
        cin >> s[i] >> t[i] >> d[i];
        G[s[i]].emplace_back((edge){t[i], d[i]});
    }
    dijkstra(r);
    for (int i = 0; i < V; i++) {
        if (d[i] == INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
    return 0;
}
