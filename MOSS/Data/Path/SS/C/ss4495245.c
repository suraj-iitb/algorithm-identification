#include <bits/stdc++.h>
using namespace std;
int main()
{
    int V, E, r;
    cin >> V >> E >> r;
    vector<vector<pair<int, int>>> g(V);
    for (int i = 0; i < E; i++)
    {
        int s, t, d;
        cin >> s >> t >> d;
        g[s].emplace_back(t, d);
    }

    vector<int> dist(V, -1);
    dist[r] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, r);
    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        for (auto v : g[p.second])
        {
            if (dist[v.first] == -1)
            {
                dist[v.first] = dist[p.second] + v.second;
                pq.emplace(dist[v.first], v.first);
            }
            else if (dist[v.first] <= dist[p.second] + v.second)
            {
                continue;
            }
            else
            {
                dist[v.first] = dist[p.second] + v.second;
                pq.emplace(dist[v.first], v.first);
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == -1)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << dist[i] << endl;
        }
    }
}
