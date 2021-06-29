#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpl;
typedef vector<vector<long long>> mll;
typedef vector<bool> vbl;

class Graph {
   public:
    enum NodeColor { VISITED, VISITING, UNVISITED };
    struct Node {
        int index;
        vpl adjacent;
        NodeColor color = UNVISITED;
    };
    vector<Node> list;
    int n;
    Graph(int n) {
        list.resize(n);
        for (int i = 0; i < n; i++)
            list[i].index = i;
        this->n = n;
    }
    void add_edge(int u, int v, long long w = 1, bool bidirectional = true) {
        list[u].adjacent.emplace_back(v, w);
        if (bidirectional)
            list[v].adjacent.emplace_back(u, w);
    }

    pair<vll, vll> dijkstra(vll from) {
        vll dist(n, INT64_MAX), parent(n, INT32_MAX);
        priority_queue<pll, vpl, greater<>> q;
        for (auto index : from) {
            dist[index] = 0;
            q.emplace(0, index);
        }
        while (!q.empty()) {
            pll top = q.top();
            q.pop();
            if (top.first > dist[top.second])
                continue;
            for (auto edge : list[top.second].adjacent) {
                if (top.first + edge.second < dist[edge.first]) {
                    dist[edge.first] = top.first + edge.second;
                    parent[edge.first] = top.second - 1;
                    q.emplace(top.first + edge.second, edge.first);
                }
            }
        }
        return {dist, parent};
    }
};

int main() {
    // Prepare the Graph
    int n, m, s;
    cin >> n >> m >> s;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        g.add_edge(u, v, w, false);
    }
    // Get the result from a call to Dijkstra
    pair<vll, vll> res = g.dijkstra({s});
    // Print the outputs
    for (int i = 0; i < n; i++) {
        if (res.first[i] == INT64_MAX)
            cout << "INF" << endl;
        else
            cout << res.first[i] << endl;
    }
    return 0;
}

