#include <bits/stdc++.h>
using namespace std;

struct edge {int to, cost;};
typedef pair<int, int> P;
const int INF=1000000000;

int main() {
    int V, E, s, d[100005];
    cin >> V >> E >> s;
    vector<vector<edge> > g(V);
    for(int i=0; i<E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge ee={b, c};
        g[a].push_back(ee);
    }

    priority_queue<P, vector<P>, greater<P> > pq;
    fill(d, d+V, INF);
    d[s]=0;
    pq.push(P(0, s));

    while(!(pq.empty())) {
        P p=pq.top();
        pq.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0; i<g[v].size(); i++) {
            edge e=g[v][i];
            if(d[e.to]>d[v]+e.cost) {
                d[e.to]=d[v]+e.cost;
                pq.push(P(d[e.to],e.to));
            }
        }
    }
    for(int i=0; i<V; i++) {
        if(d[i]==INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }





}
