# include <bits/stdc++.h>
# define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define len(x) ((int)(x).size())
# define pb push_back
# define int long long
using namespace std;

struct Graph
{
    Graph() = default;
    Graph(int v, int e) : V(v), E(e)
    {
        adj = vector<vector<int>>(V);
        cost = vector<vector<int>>(V);
    }

    void connect_to(int a, int b, int c = 0)
    {
        adj[a].pb(b);
        cost[a].pb(c);
    }

    vector<int> dijkstra(int ini)
    {
        using P = pair<int, int>;
        vector<int> dist(V, -1);
        vector<bool> visited(V, false);
        priority_queue<P, vector<P>, greater<P>> que;
        que.emplace(0, ini);
        while (not que.empty())
        {
            int d = que.top().first, to = que.top().second; que.pop();
            if (visited[to]) continue;
            dist[to] = d;
            visited[to] = true;

            rep (i, len(adj[to]))
            {
                int nxt = adj[to][i];
                int c = cost[to][i];
                if (dist[nxt] != -1 and dist[nxt] <= dist[to] + c) continue;
                que.emplace(dist[to] + c, nxt);
            }
        }
        return dist;
    }

    vector<vector<int>> adj;  // 隣接リスト本体
    vector<vector<int>> cost;  // 重み
    int V;  // 頂点数
    int E;  // 辺数
};

signed main()
{
    int V, E, r;
    cin >> V >> E >> r;
    Graph g(V, E);
    rep (i, E) {
        int s, t, d;
        cin >> s >> t >> d;
        g.connect_to(s, t, d);
    }

    vector<int> dist = g.dijkstra(r);

    auto Ans = [](int d) {
        if (d == -1){ string ret = "INF"; return ret; }
        else return to_string(d);
    };
    rep (i, V) cout << Ans(dist[i]) << endl;

    return 0;
}

