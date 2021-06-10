#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

struct Edge
{
    int from, to, cost;
    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool operator<(const Edge &e, const Edge &f)
{
    return e.cost > f.cost;
}

vector<int> dijkstra(const Graph &g, int s)
{
    vector<int> d(g.size(), INF);
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, s)); // P(dis, pos)
    while (!que.empty())
    {
        int dist = que.top().first;
        int v = que.top().second;
        que.pop();
        if (d[v] < dist)
            continue;
        for (const auto &e : g[v])
        {
            if (d[e.to] <= d[v] + e.cost)
                continue;
            d[e.to] = d[v] + e.cost;
            que.push(P(d[e.to], e.to));
        }
    }
    return d;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int V, E, r;
    cin >> V >> E >> r;
    Graph g(V);
    for (int i = 0; i < E; i++)
    {
        int s, t, d;
        cin >> s >> t >> d;
        g[s].push_back(Edge{s, t, d});
    }
    vector<int> ret = dijkstra(g, r);
    for (int i = 0; i < V; i++)
    {
        cout << (ret[i] == INF ? "INF" : to_string(ret[i])) << endl;
    }
}

