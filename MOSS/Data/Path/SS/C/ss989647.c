#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
#define MAXV 100000
#define INF 1e9

int V, E, r;
struct edge{int to, cost;};
typedef pair<int, int> P; // firstは最短距離、secondは頂点番号

vector<edge> G[MAXV];
int d[MAXV];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
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
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(void) {
    cin >> V >> E >> r;
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        edge e; e.to = t; e.cost = d;
        G[s].push_back(e);
    }
    dijkstra(r);
    for (int i = 0; i < V; i++) {
        if (d[i] < INF) cout << d[i] << endl;
        else cout << "INF" << endl;
    }
    return 0;
}
