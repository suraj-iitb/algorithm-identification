#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr ll INF = 1e15;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << (v[i]==INF ? "INF" : to_string(v[i])) << " \n"[i == sz - 1];
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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;
    vector<vector<ll>> ret(V, vector<ll>(V, INF));
    for (int i = 0; i < V; i++)
        ret[i][i] = 0;
    for (int i = 0; i < E; i++)
    {
        int s, t, d;
        cin >> s >> t >> d;
        ret[s][t] = d;
    }
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (ret[i][k] == INF || ret[k][j] == INF)
                    continue;
                ret[i][j] = min(ret[i][j], ret[i][k] + ret[k][j]);
            }
        }
    }
    bool f = false;
    for (int i = 0; i < V; i++)
        if (ret[i][i] < 0)
            f = true;
    if (f)
        cout << "NEGATIVE CYCLE" << endl;
    else
    {
        for (int i = 0; i < V; i++)
            printv(ret[i]);
    }
}

