#include <iostream>
#include <vector>
#include <queue>
using namespace std;
long long inf = 1LL << 60;

struct Edge
{
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

bool chmin(long long &a, long long b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    else
        return false;
}

int main()
{
    int N, M, s;
    cin >> N >> M >> s;

    Graph G(N);
    for (int i = 0; i < M; ++i)
    {
        int j, k, w;
        cin >> j >> k >> w;
        G[j].push_back(Edge(k, w));
    }

    vector<long long> dist(N, inf);
    dist[s] = 0;
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        que;

    que.push(make_pair(dist[s], s));
    while (!que.empty())
    {
        int v = que.top().second;      // 探索する頂点
        long long d = que.top().first; // vの現在のコスト
        que.pop();



        for (auto e : G[v])
        {
            if (chmin(dist[e.to], dist[v] + e.w))
            {
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        if (dist[i] < inf)
            cout << dist[i] << endl;
        else
            cout << "INF" << endl;
    }
}



