  #include<bits/stdc++.h>
using namespace std;
#define sci(n)               scanf("%d",&n)
#define scl(n)               scanf("%lld",&n)
#define scd(n)               scanf("%lf",&n)
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define loop(a,b)            for(ll i=a;i<=b;i++)
#define ll long long
struct Node
{
    ll u,cost;
    Node(ll _u,ll _cost)
    {
        u=_u;
        cost=_cost;
        //cout << "X" << endl;
    }
};
bool operator<(Node A,Node B)
{
    return A.cost>B.cost;
}
priority_queue<Node>PQ;
ll dist[100005];
vector<ll>graph[100005];
ll nodes,edges,s;
vector<ll>cost[100005];
//cout << "Y" << endl;
void dijkstra(ll s)
{
    //cout << "Z" << endl;
    for(ll i=0;i<nodes;i++)
    {
        dist[i]=10000000000;
    }
    //cout << "Z" << endl;
    dist[s]=0;
    PQ.push(Node(s,0));
    while(!PQ.empty())
    {
        Node top=PQ.top();
        PQ.pop();
        ll u=top.u;
        for(ll i=0;i<graph[u].size();i++)
        {
            ll v=graph[u][i];
            if(dist[u]+cost[u][i]<dist[v])
            {
                dist[v]=dist[u]+cost[u][i];
                PQ.push(Node(v,dist[v]));
            }
        }
    }
    LOOP(i,nodes)
    {
        if(dist[i]==10000000000)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << dist[i] << endl;
        }
    }
}
int main()
{

    scl(nodes);
    scl(edges);
    scl(s);
    ll x,y,z;
    LOOP(i,edges)
    {
        scl(x);
        scl(y);
        scl(z);
        graph[x].push_back(y);
        //graph[y].push_back(x);
        cost[x].push_back(z);
        //cost[y].push_back(z);
    }
    dijkstra(s);
}



