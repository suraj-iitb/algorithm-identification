#include <iostream>
#include <queue>
using namespace std;

template <typename T>
struct Edge
{
    int to;
    T cost;
};

template <typename T>
struct WeightedGraph
{
    int n;
    std::vector<std::vector<Edge<T>>> g;
    
    WeightedGraph(){}
    
    WeightedGraph(int n) : n(n){
        g.resize(n);
    }
    
    void add_edge(int from, int to, T cost){
        g[from].push_back((Edge<T>){to, cost});
    }
};

template <typename T>
std::vector<T> dijkstra(WeightedGraph<T> &g, int s){
    int n = g.n;
    std::vector<T> d(n);
    fill(d.begin(), d.end(), -1);
    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> que;
    d[s] = 0;
    que.push(std::pair<T, int>(0, s));
    while(que.size()){
        std::pair<T, int> p = que.top();
        que.pop();
        int u = p.second;
        if(d[u] < p.first) continue;
        for(Edge<T> &e : g.g[u]){
            int v = e.to;
            if(d[v] == -1 || d[v] > d[u] + e.cost){
                d[v] = d[u] + e.cost;
                que.push(std::pair<T, int>(d[v], v));
            }
        }
    }
    return d;
}

int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    WeightedGraph<int> g(n);
    for(int i = 0; i < m; i++){
        int s, t, d;
        cin >> s >> t >> d;
        g.add_edge(s, t, d);
    }
    vector<int> d = dijkstra<int>(g, r);
    for(int i = 0; i < n; i++){
        if(d[i] == -1) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
}

