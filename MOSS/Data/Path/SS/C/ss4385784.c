#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
ll INF = 1145141919810364;
template <typename T>
class edge
{
public:
    T cost, to, from;
    edge(T from, T to, T cost) : from(from), to(to), cost(cost) {}
};
template <typename T>
class Graph
{
public:
    vector<vector<edge<T>>> graph;

    Graph(T n, vector<T> from, vector<T> to, bool no_direction, vector<T> cost)
    {
        graph.resize(n);
        for (int i = 0; i < from.size(); i++)
        {
            edge<T> params(from[i], to[i], cost[i]);
            graph[from[i]].emplace_back(params);
            if (no_direction)
            {
                swap(params.from, params.to);
                graph[to[i]].emplace_back(params);
            }
        }
    }
    vector<ll> shortest_path;
    void Dijkstra(ll start)
    {
        shortest_path.resize(graph.size(), INF);
        shortest_path[start] = 0;
        priority_queue<P, vector<P>, greater<P>> que;
        que.emplace(0, start);
        while (!que.empty())
        {
            P p = que.top();
            que.pop();
            ll v = p.second;
            if (shortest_path[v] < p.first)
                continue;
            for (int i = 0; i < graph[v].size(); i++)
            {
                ll k = graph[v][i].to;
                ll l = graph[v][i].cost;
                if (shortest_path[k] > shortest_path[v] + l)
                {
                    shortest_path[k] = shortest_path[v] + l;
                    que.push(P(shortest_path[k], k));
                }
            }
        }
    }
};

int main()
{
    ll v, e, r;
    scanf("%lld%lld%lld", &v, &e, &r);
    vector<ll> s(e), t(e), d(e);
    for (int i = 0; i < e; i++)
    {
        scanf("%lld%lld%lld", &s[i], &t[i], &d[i]);
    }
    Graph<ll> graph(v, s, t, false, d);
    graph.Dijkstra(r);
    for (int i = 0; i < v; i++)
    {
        if (graph.shortest_path[i] == INF)
            printf("%s\n", "INF");
        else
        {
            printf("%lld\n", graph.shortest_path[i]);
        }
    }
}
