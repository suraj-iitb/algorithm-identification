#include<bits/stdc++.h>
#define ll long long
#define inf 2147483647 
using namespace std;
struct edge{//储存边的信息 
    int v;
    ll cost;
};
struct node{//堆内的结构体 pos:节点编号，num：距离 
    int pos;
    ll num;
    friend bool operator < (node a,node b)//堆 运算符重载（按照num最小堆） 
    {
        return a.num>b.num;
    }
};
int n,m,s;
vector<edge> mp[100010];//邻接表+vector存图 
ll dis[100010];//距离各点的距离 
bool book[100010];//标记是否处理过 
priority_queue<node> q;//最小堆优化 
void Dijkstra()//算法框架 
{
    for(int i=0;i<n;i++)//将节点依次存入堆 
    {
        node t;
        t.pos=i;t.num=dis[i];
        q.push(t);
    }
    book[s]=true;//起点已经取过了 
    while(!q.empty())//精华部分 
    {
        node t=q.top();
        if(book[t.pos])//懒惰删除 
        {
            q.pop();
            continue;
        }
        book[t.pos]=true;
        for(int j=0;j<mp[t.pos].size();j++)//实现按边的松弛 
        {
            edge tmp=mp[t.pos][j];
            if(dis[tmp.v]>dis[t.pos]+tmp.cost)
            {
                dis[tmp.v]=dis[t.pos]+tmp.cost;
                q.push((node){tmp.v,dis[tmp.v]});//将更新的值存入堆 
            }
             
        }
        q.pop();
    }
}
void init()//初始化 不解释 
{
    for(int i=0;i<n;i++)
    dis[i]=(i==s?0:inf);
}
int main()//主函数 
{
    cin>>n>>m>>s;
    init();
    memset(book,false,sizeof(book));
    for(int i=0;i<m;i++)//邻接表将节点存入 
    {
        int x;
        edge y;
        scanf("%d%d%lld",&x,&y.v,&y.cost);
        if(x==s) dis[y.v]=min(dis[y.v],y.cost);
        mp[x].push_back(y);
    }
    Dijkstra();//跑一边算法 
    for(int i=0;i<n;i++)
        if(dis[i]!=inf) printf("%lld\n",dis[i]);//输出结果 
        else printf("INF\n");
    return 0;
}
