#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define rep(i, s, g) for ((i) = (s); (i) < (g); ++(i))
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll MOD = 1e9 + 7;
const ll INF = (1e18) + 1;

struct edge
{
    ll to;
    ll cost;
};

int V;
vector<edge> G[1000010];
vector<ll> d(1000010);

void dijkstra(int s)
{
    int i;
    priority_queue<P, vector<P>, greater<P>> q;
    fill(d.begin(), d.end(), INF);
    d[s] = 0;
    q.push(P(0, s));

    while (q.size())
    {
        P p = q.top();
        q.pop();
        int v = p.second;

        if (d[v] < p.first)
        {
            continue;
        }

        for (auto &x : G[v])
        {
            edge e = x;

            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                q.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(void)
{
    int V, E, r;
    cin >> V >> E >> r;
    int i;
    ll x, y, z;

    rep(i, 0, E)
    {
        edge e;
        cin >> x >> y >> z;
        e.to = y;
        e.cost = z;
        G[x].push_back(e);
    }

    dijkstra(r);

    rep(i, 0, V)
    {
        if (d[i] == INF)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << d[i] << endl;
        }
    }
}
