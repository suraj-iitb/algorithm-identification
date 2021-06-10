#include <bits/stdc++.h>
#include <cmath>

using namespace std;



//input condition
const long long MAX_V = 100000;
const long long MAX_E = 500000;
const long long MAX_D = 10000;
const long long INF = MAX_E * MAX_D;

struct edge {
    long long to, cost;
};
typedef pair<long long, long long> P;

//input data
long long V, E, s;
vector<edge> G[MAX_V];
// input start, end, cost
// edge E; E.to = end; E.cost = cost;
// G[start].push_back(E);

long long d[MAX_V];

void dijkstra(long long s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        long long v = p.second;
        if (d[v] < p.first) continue;
        for (long long i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    cin >> V >> E >> s;
    for(long long i = 0; i < E; i++) {
        long long start;
        edge x;
        cin >> start >> x.to >> x.cost;
        G[start].push_back(x);
    }

    dijkstra(s);

    for(long long i = 0; i < V; i++) {
        if(d[i] == INF) {
            cout << "INF" << endl;
        } else {
            cout << d[i] << endl;
        }
    }

    return 0;
}
