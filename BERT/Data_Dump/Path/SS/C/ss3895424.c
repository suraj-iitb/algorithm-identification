#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;

constexpr int MAX_V = 100000;
constexpr ll INF = 1LL << 60;

int V, E, r;
vector<Pll> graph[MAX_V];
vector<ll> dist(MAX_V, INF);

void dijkstra(int start) {
    priority_queue<Pll, vector<Pll>, greater<Pll>> que;
    dist[start] = 0;
    que.emplace(0, start);
    int node; ll d;
    while(!que.empty()) {
        tie(d, node) = que.top(); que.pop();
        if(dist[node] < d) continue;
        for(Pll nxt: graph[node]) {
            if(dist[nxt.first] > dist[node] + nxt.second) {
                dist[nxt.first] = dist[node] + nxt.second;
                que.emplace(dist[nxt.first], nxt.first);
            }
        }
    }
}

int main() {
    cin >> V >> E >> r;
    int s, t; ll d;
    for(int i=0;i<E;++i){
        cin >> s >> t >> d;
        graph[s].emplace_back(t, d);
    }

    dijkstra(r);

    for(int i=0;i<V;++i) {
        if(dist[i] == INF) {
            cout << "INF\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
}
