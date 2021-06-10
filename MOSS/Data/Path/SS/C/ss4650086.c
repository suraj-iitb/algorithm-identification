
#include <iostream>
#include <vector>
#include <queue>

#define INF (1<<30)

using namespace std;
using p = pair<int, int>;
using Graph = vector<vector<p>>;

int dijkstra(Graph& g, int& s)
{
    priority_queue<p, vector<p>, greater<p>> q;
    vector<int> dist(g.size(), INF);
    dist[s]=0;
    q.push(p(0, s));

    while (!q.empty())
    {
        p pi = q.top(); q.pop();
        int v = pi.second;
        if (dist[v]<pi.first) continue;

        int to, cost;
        for (size_t k=0; k<g[v].size(); ++k)
        {
            p i (g[v][k]);
            to = i.second;
            cost = i.first;
            if (dist[to] > dist[v] + cost)
                dist[to] = dist[v] + cost, q.push(p(dist[to], to));
        }
    }

    for (size_t i=0; i<dist.size(); ++i)
        if (dist[i] < INF)
            cout << dist[i] << endl;
        else
            cout << "INF" << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int V, E, r;
    cin >> V >> E >> r;

    Graph g(V);
    for (int i=0; i<E; i++)
    {
        int a, b, c;
        cin >> a >> b >>c;
        g[a].emplace_back(c, b); 
    }

    dijkstra(g, r);
}



