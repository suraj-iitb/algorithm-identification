#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = (int)1e9;

// graph template
template<typename T>
class edge{
    public:
        int src, to; T cost;

        edge(int to, T cost): src(-1), to(to), cost(cost){}
        edge(int src, int to, T cost): src(src), to(to), cost(cost){}
};
template<typename T>
using Edges = vector<edge<T>>;
template<typename T>
using AdjacencyList = vector<Edges<T>>;
template<typename T>
using Matrix = vector<vector<T>>;

template<typename T>
vector<T> dijkstra(AdjacencyList<T> &g, int s){
    const auto INF = numeric_limits<T>::max();
    vector<T> dist(g.size(), INF);

    using Pr = pair<T, int>;
    priority_queue<Pr, vector<Pr>, greater<Pr>> que;
    dist[s] = 0;
    que.emplace(dist[s], s);

    while(not que.empty()){
        T cost; int v;
        tie(cost, v) = que.top(); que.pop();
        if(dist[v] < cost) continue;

        for(auto &e: g[v]){
            if(dist[e.to] > dist[v] + e.cost){
                dist[e.to] = dist[v] + e.cost;
                que.emplace(dist[e.to], e.to);
            }
        }
    }

    return dist;
}

int main(void){
    int V, E, R;
  scanf("%d %d %d", &V, &E, &R);
  AdjacencyList< int > g(V);
  for(int i = 0; i < E; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    g[a].emplace_back(b, c);
  }
  for(auto &dist : dijkstra(g, R)) {
    if(dist == numeric_limits< int >::max()) puts("INF");
    else printf("%d\n", dist);
  }

    return 0;
}
