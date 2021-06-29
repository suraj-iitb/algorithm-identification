#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(obj) obj.begin(), obj.end()

const int iINF = 1e9;
const long long llINF = 1e18;
const int MOD = 1e9 + 7;

using namespace std;

template <typename T>
struct Dijkstra {
    using P = pair<T, int>;

    int n;
    T initial;
    vector<vector<P>> graph;

    Dijkstra(int n, vector<vector<P>> graph, T initial)
        : n(n), graph(graph), initial(initial) {}

    vector<T> solve(int start) {
        vector<bool> used(n, false);
        vector<T> dist(n, initial);
        priority_queue<P, vector<P>, greater<P>> que;
        que.push(make_pair(0, start));
        while(!que.empty()) {
            T d; int t;
            tie(d, t) = que.top(); que.pop();
            if (used[t]) continue;
            used[t] = true; dist[t] = d;
            for (auto &e : graph[t]) {
                if (dist[e.second] <= d + e.first) continue;
                que.push(make_pair(d + e.first, e.second));
            }
        }
        return dist;
    }
};

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    vector<vector<pair<int, int>>> graph(V, vector<pair<int, int>>());
    REP(i, E) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s].push_back(make_pair(d, t));
    }
    Dijkstra<int> dijkstra(V, graph, iINF);
    auto ans = dijkstra.solve(r);
    for(auto x : ans) {
        cout << (x == iINF ? "INF" : to_string(x)) << endl;
    }
}
