#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dump(...)
#endif
#define endl "\n"
#define ll long long
#define BUF 1e5
#define INF 1 << 30
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(a) (a).begin(), (a).end()
#define bit(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
constexpr ll mod = 1e9 + 7;
ll A, B, C, D, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;
ll ans = 0;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec)
        is >> x;
    return is;
}

class Graph {
    struct edge {
        int from, to, cost;
        edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
    };

public:
    int verN;
    int edgeN = 0;
    bool single_source_flag = 0;
    vector<edge> edge_set;
    vector<vector<pair<int, int>>> adj_list;
    vector<vector<int>> dist_all_pairs;
    vector<int> dist_single_source;
    Graph(int verN) : verN(verN), adj_list(verN), dist_single_source(verN, INF) {}

    void add_directed_edge(int from, int to, int cost = 1) {
        edge_set.push_back(edge(from, to, cost));
        adj_list[from].push_back(make_pair(to, cost));
        edgeN++;
    }

    void add_undirected_edge(int from, int to, int cost = 1) {
        edge_set.push_back(edge(from, to, cost));
        edge_set.push_back(edge(to, from, cost));
        adj_list[from].push_back(make_pair(to, cost));
        adj_list[to].push_back(make_pair(from, cost));
        edgeN += 2;
    }

    bool bellmanford(int start) {
        single_source_flag = 1;
        vector<int> &d = dist_single_source;
        for (int i = 0; i < verN; i++) {
            d[i] = INF;
        }
        d[start] = 0;
        for (int i = 0; i < verN; i++) {
            for (int j = 0; j < edgeN; j++) {
                edge e = edge_set[j];
                if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                    d[e.to] = d[e.from] + e.cost;
                    if (i == verN - 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void dijkstra(int start) {
        single_source_flag = 1;
        vector<int> &d = dist_single_source;
        d[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> used(verN, 0);
        pq.push(make_pair(0, start));
        while (!pq.empty()) {
            int now = pq.top().second;
            pq.pop();
            used[now] = 1;
            dump(now);
            for (auto adj_pair : adj_list[now]) {
                int adj = adj_pair.first;
                int dist = adj_pair.second;
                if (used[adj])
                    continue;
                if (d[adj] > d[now] + dist) {
                    d[adj] = d[now] + dist;
                    pq.push(make_pair(d[adj], adj));
                }
            }
        }
    }

    void warshallfloyd() {
        dist_all_pairs.resize(verN, vector<int>(verN, INF));
        for (int i = 0; i < verN; i++) {
            for (auto adj_pair : adj_list[i]) {
                int adj = adj_pair.first;
                int dist = adj_pair.second;
                dist_all_pairs[i][adj] = dist;
            }
        }
        for (int k = 0; k < verN; k++) {         // 経由する頂点
            for (int i = 0; i < verN; i++) {     // 始点
                for (int j = 0; j < verN; j++) { // 終点
                    dist_all_pairs[i][j] = min(dist_all_pairs[i][j], dist_all_pairs[i][k] + dist_all_pairs[k][j]);
                }
            }
        }
    }

    int get_shortest_path(int end) {
        assert(single_source_flag == 1);
        return dist_single_source[end];
    }

    int get_shortest_path(int start, int end) {
        assert(dist_all_pairs.size() != 0);
        return dist_all_pairs[start][end];
    }
};

signed main() {
    int start;
    cin >> N >> M >> start;
    Graph g(N);
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        g.add_directed_edge(A, B, C);
    }
    g.dijkstra(start);
    for (int i = 0; i < N; i++) {
        int tmp = g.get_shortest_path(i);
        if (tmp == INF) {
            cout << "INF" << endl;
        } else
            cout << tmp << endl;
    }
}
