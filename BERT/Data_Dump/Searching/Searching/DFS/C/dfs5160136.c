#include<stdio.h>

#define N 100
#define WHITE 0
#define BLACK 1
#define GRAY  2

void visit(int);
void dfs();

int color[N+1],time;
int d[N+1],f[N+1];
int M[N+1][N+1],n;

int main()
{
  int i,j,u,k,v;

  scanf("%d",&n);
  
  for(i=1;i<n+1;i++)  
  {
    for(j=1;j<n+1;j++)
    {
      M[i][j]=0;
    }
  }

  time=0;

  for(i=1;i<n+1;i++)   
  {
    scanf("%d",&u);
    scanf("%d",&k);
    
    for(j=1;j<k+1;j++) 
    {
      scanf("%d",&v);
      M[u][v]=1;

    }
    
  }

  dfs();


  return 0;
}

void visit(int u)
{
  int v;

  color[u]=GRAY;
  d[u]=++time;
  
  for(v=1;v<n+1;v++)
  {
    if(M[u][v]==0) continue;
    if(color[v]==WHITE) visit(v);
  }
  color[u]=BLACK;
  f[u]=++time;

  
}

void dfs()
{
  int u;

  for(u=1;u<n+1;u++) color[u]=WHITE;
  time=0;

  for(u=1;u<n+1;u++)
  {
    if(color[u]==WHITE) visit(u);
  }

  for(u=1;u<n+1;u++)
  {
    printf("%d %d %d\n",u,d[u],f[u]);
  }
}



