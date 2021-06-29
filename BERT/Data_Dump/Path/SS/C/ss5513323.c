#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int MAX_n = 100000;
const int INF = 0x3f3f3f3f;
typedef pair<int,int> pii;   //destination,weighted
vector<pii> G[MAX_n];
int d[MAX_n];             //distance:min(source->this node)
bool used[MAX_n];
priority_queue<pii> que;


//有向权重graph
void add_edge(int v,int u,int c)
{
   G[v].push_back(pii(u,c));
}

//松弛
bool relax(int v,int u,int c)
{
    if(d[u]>d[v]+c&&d[v]!=INF)
    {
        d[u]=d[v]+c;
        return true;
    }
    return false;
}

//堆优化heap
void Dij(int r,int n)   //n:amount of node
{
    
    //初始化
    for(int i=0;i<n;++i) d[i]=INF;
    d[r]=0;
    que.push(pii(-d[r],r));
    
    while(!que.empty())
    {
        //找到离收敛集合距离最小的node
        pii p=que.top();  que.pop();
        int dv=-p.first,v=p.second;
        
        if(used[v]&&dv>d[v])  continue;
        //加入集合
        used[v]=true;
        //更新相邻结点的松弛
        for(int i=0;i<G[v].size();++i)
        {
             pii q=G[v][i]; 
             int u=q.first,du=q.second;
             if(relax(v,u,du))
             {
                 que.push(pii(-du,u));
             }
        }
        
    }
}


int main()
{
    int n,e,r;
    scanf("%d %d %d",&n,&e,&r);
    
    for(int i=0;i<e;++i)
    {
        int v,u,c;
        scanf("%d %d %d",&v,&u,&c);
        add_edge(v,u,c);
    }
    
    
    Dij(r,n);
    
     for(int i=0;i<n;++i)
        {
            if(d[i]==INF)
            {
                printf("INF\n");
            }else
            {
                printf("%d\n",d[i]);   
            }
        }

  
}




