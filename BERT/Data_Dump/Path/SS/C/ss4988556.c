#include"bits/stdc++.h"
using namespace std;
const int manx = 110000;
const int inf = 0x3fffffff;
struct node{
    int to,cost;
    node(int a,int b)
    {
        to=a,cost=b;
    }
};
vector<node> g[manx];
int d[manx],n,m,s;
typedef pair<int,int> p;
void dijkstra(int s)
{
    fill(d,d+manx,inf);
    d[s]=0;
    priority_queue<p,vector<p>,greater<p> >que;
    que.push(p(0,s));
    while(que.size())
    {
        p t=que.top();
        que.pop();
        int v=t.second;
        if(d[v]<t.first)continue;
        for(int i=0;i<g[v].size();i++)
        {
            node a=g[v][i];
            if(d[a.to]>d[v]+a.cost)
            {
                d[a.to]=d[v]+a.cost;
                que.push(p(d[a.to],a.to));
            }
        }
    }
}
int main()
{
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(node(b,c));
    }
    dijkstra(s);
    for(int i=0;i<n;i++)
    {
        if(d[i]!=inf)cout<<d[i]<<endl;
        else cout<<"INF"<<endl;
    }
    return 0;
}
