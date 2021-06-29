#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define mp make_pair
#define fi first
#define se second

struct dijkstra
{
    struct edge{int to,cost,rev;};
    using Graph =vector<vector<edge>>;
    Graph graph;
    int V;
public:
    vector<int> dis;
    dijkstra(int n)
    {
        V=n;
        graph.resize(V);
        dis.resize(V,INF);
    }

    void add_edge(int from,int to,int cost) //戻り篇なし
    {
        graph[from].push_back((edge){to,cost,(int)graph[to].size()});
    }

    void run(int s)
    {
        dis[s]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
        que.push(mp(dis[s],s));
        int u,v;
        while (!que.empty())
        {
            u=que.top().se;
            que.pop();
            for (int i=0;i<graph[u].size();i++)
            {
                edge e=graph[u][i];
                if (dis[e.to]>dis[u]+e.cost)
                {
                    dis[e.to]=dis[u]+e.cost;
                    que.push(mp(dis[e.to],e.to));
                }
            }
        }
        return ;
    }
};

int main()
{
    int V,E,r;cin >> V >> E >> r;
    dijkstra solve(V);
    int s,t,d;
    for (int i=0;i<E;i++)
    {
        cin >>s >> t >> d;
        solve.add_edge(s,t,d);
    }
    solve.run(r);
    for (int i=0;i<V;i++)
    {
        if (solve.dis[i]==INF) cout << "INF" << endl;
        else cout << solve.dis[i] << endl;
    }
    return 0;
}
