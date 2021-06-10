#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int MAX_V = 1000;
int dist[MAX_V];

typedef pair<int, int> P;

struct edge
{
    int to, cost;
};
typedef vector<vector<edge>> Graph;

vector<int> dijkstra(Graph &G, int s)
{
    vector<int> dist(G.size(), INF);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(make_pair(0, s));
    while (!pq.empty())
    {
        P t = pq.top();
        pq.pop();
        if (t.first > dist[t.second])
            continue;
        dist[t.second] = t.first;
        for (edge &e : G[t.second])
        {
            if (dist[t.second] + e.cost < dist[e.to])
            {
                pq.push(make_pair(dist[t.second] + e.cost, e.to));
            }
        }
    }
    return dist;
}

int main()
{
    int V, E, r;
    cin >> V >> E >> r;
    Graph G(V);
    for (int i = 0; i < E; ++i)
    {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back((edge){t, d});
    }
    vector<int> dist = dijkstra(G, r);
    for (int i = 0; i < (int)dist.size(); ++i)
    {
        if (dist[i] == INF)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << dist[i] << endl;
        }
    }

    return 0;
}
