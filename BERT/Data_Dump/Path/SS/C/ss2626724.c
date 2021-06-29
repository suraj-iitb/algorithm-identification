#include "bits/stdc++.h"
using namespace std;
int main()
{
    int v, e, r, inf = 1000000000;
    scanf("%d %d %d", &v, &e, &r);
    vector<vector<pair<int, int>>> a(v, vector<pair<int, int>>(0));
    for (int i = 0, s, t, d; i < e; i++)
    {
        scanf("%d %d %d", &s, &t, &d);
        a[s].push_back(make_pair(d, t));
    }
    vector<int> cost(v, inf), vis(v, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    cost[r] = 0;
    q.push(make_pair(0, r));
    for (pair<int, int> t; !q.empty(); )
    {
        t = q.top();
        q.pop();
        vis[t.second] = true;
        if (cost[t.second] < t.first)
        {
            continue;
        }
        for (int i = 0; i < a[t.second].size(); i++)
        {
            if (!vis[a[t.second][i].second] && cost[a[t.second][i].second] > cost[t.second] + a[t.second][i].first)
            {
                cost[a[t.second][i].second] = cost[t.second] + a[t.second][i].first;
                q.push(make_pair(cost[a[t.second][i].second], a[t.second][i].second));
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        printf(cost[i] >= inf ? "INF\n" : "%d\n", cost[i]);
    }
}
