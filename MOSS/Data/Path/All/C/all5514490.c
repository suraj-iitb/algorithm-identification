#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX_n = 100;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
long long G[MAX_n][MAX_n];//二维邻接矩阵

void init_G(int n)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
             if(i!=j)
             {
                 G[i][j]=INF;
             }
        }
    }
}
//有向权重graph
void add_edge(int v,int u,int c)
{
    //G[v][u]=min(G[v][u],c);
      G[v][u]=c;
}

bool floyd_warshall(int n)
{
      for(int k=0;k<n;++k)
      {
          for(int i=0;i<n;++i)
          {
              for(int j=0;j<n;++j)
              {
                  if(G[i][k]==INF||G[k][j]==INF) continue;
                  
                  G[i][j]=min(G[i][j],G[i][k]+G[k][j]);          //检测通过中转能否使距离变短
              }
          }
      }
    
     //判断负环
     for(int i=0;i<n;++i)
      for(int j=0;j<n;++j)
      {
          if(i==j&&G[i][j]!=0)
          return false;
      }
      
     return true; 
}

int main()
{
    int n,e;
    scanf("%d %d",&n,&e);
    
    init_G(n);
    
    for(int i=0;i<e;++i)
    {
        int v,u,c;
        scanf("%d %d %d",&v,&u,&c);
        add_edge(v,u,c);
    }
    
    if(floyd_warshall(n))
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                    if(j==n-1)
                    {
                         if(G[i][j]==INF)
                         printf("INF");
                         else
                         printf("%d",G[i][j]);
                    }
                    else
                    {
                         if(G[i][j]==INF)
                         printf("INF ");
                         else
                         printf("%d ",G[i][j]);
                    }
            }
            printf("\n");
        }
    }else
    {
        printf("NEGATIVE CYCLE\n");
    }
}





