#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define EPS (1e-7)
#define INF (1 << 30)
#define LLINF (1LL << 60)
#define PI (acos(-1))
#define MOD (1000000007)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

const int MAX_V = 100000;

// 行き先toとコストcost
struct edge
{
    int to;
    int cost;
};
typedef pair<int, int> P; // firstは最短距離、secondは頂点の番号

// int V;
// vector<edge> graph[MAX_V]; // グラフ(隣接リスト)
// int d[MAX_V];              //最短距離

void dijkstra(int s, vector<vector<edge>> &graph, vector<int> &d, int V)
{
    priority_queue<P, vector<P>, greater<P>> pq;
    fill(d.begin(), d.begin() + V, INF);
    d[s] = 0;
    pq.push(P(0, s));

    while (!pq.empty())
    {
        P p = pq.top(); // 未確定の中から確定させた頂点
        pq.pop();
        int v = p.second; // 取り出した頂点の番号
        // もう探索する必要のない経路がpqに残っていた場合は枝刈り
        if (d[v] < p.first)
        {
            continue;
        }

        for (int i = 0; i < (int)graph[v].size(); i++)
        {
            edge e = graph[v][i];
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                pq.push(P(d[e.to], e.to));
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V, E, r;
    cin >> V >> E >> r;
    vector<vector<edge>> g(V);
    for (int i = 0; i < E; i++)
    {
        int s, t, d;
        cin >> s >> t >> d;
        g[s].push_back(edge{t, d});
    }
    vector<int> dist(V);
    dijkstra(r, g, dist, V);
    for (auto ans : dist)
    {
        cout << (ans == INF ? "INF" : to_string(ans)) << endl;
    }
}
