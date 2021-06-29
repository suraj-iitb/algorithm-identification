#include <bits/stdc++.h>
#define rep(i, n) for (i = 0; i < n; i++)
using namespace std;

#define INF 1e9
int main()
{
    int V, E, r;
    int i, j;
    int d[100000];

    vector<vector<pair<int, int> > > edges(100000);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;

    cin >> V >> E >> r;
    rep(i, V) d[i] = INF;
    rep(i, E)
    {
        int s, t, c;
        cin >> s >> t >> c;
        edges[s].push_back({t, c});
        Q.push({c, t});
    }
    d[r] = 0;
    Q.push({0, r});
    while (Q.size() > 0)
    {
        pair<int, int> tmp = Q.top();
        Q.pop();
        rep(i, edges[tmp.second].size())
        {
            if (d[tmp.second] + edges[tmp.second][i].second < d[edges[tmp.second][i].first])
            {
                d[edges[tmp.second][i].first] = d[tmp.second] + edges[tmp.second][i].second;
                Q.push({d[tmp.second] + edges[tmp.second][i].second, edges[tmp.second][i].first});
            }
        }
    }
    rep(i, V)
    {
        if (d[i] != INF)
            cout << d[i] << endl;
        else
            cout << "INF" << endl;
    }

    return 0;
}

