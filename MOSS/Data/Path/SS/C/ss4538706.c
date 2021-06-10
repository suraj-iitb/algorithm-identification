#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct Edge {
    long long from;
    long long to;
    long long cost;
};
struct edge {
    long long to;
    long long cost;
};
typedef vector<vector<edge> > graph;
typedef pair<long long, long long> P;
const long long INF = 1e18;
void dijkstra(graph& G, long long start, vector<long long>& dis) {
    long long N = G.size();
    dis.resize(N, INF);
    priority_queue<P, vector<P>, greater<P> >Q;
    dis.at(start) = 0;
    Q.push(make_pair(dis.at(start), start));
    while (!Q.empty()) {
        P v = Q.top(); Q.pop();
        if (dis.at(v.second) < v.first) continue;
        for (long long i = 0; i < G[v.second].size(); i++) {
            edge next_v = G.at(v.second).at(i);
            if (dis.at(next_v.to) > dis.at(v.second) + next_v.cost) {
                dis.at(next_v.to) = dis.at(v.second) + next_v.cost;
                Q.push(make_pair(dis.at(next_v.to), next_v.to));
            }
        }
    }
    for (long long i = 0; i < dis.size(); i++) {
        if (dis.at(i) != INF) cout << dis.at(i) << endl;
        else cout << "INF" << endl;
    }
}
int main() {
    long long V, E; cin >> V >> E;
    long long start;
    cin >> start;
    graph G(V);
    vector<long long>D(V, INF);
    D.at(start) = 0;
    for (long long i = 0; i < E; i++) {
        Edge A;
        cin >> A.from >> A.to >> A.cost;
        edge B = { A.to, A.cost };
        G.at(A.from).push_back(B);
    }
    dijkstra(G, start, D);
}
