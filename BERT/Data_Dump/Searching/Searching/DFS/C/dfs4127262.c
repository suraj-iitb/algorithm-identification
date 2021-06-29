#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
int color[N],d[N],f[N],M[N][N],n,time;
void dfs();
void visit(int);
int main()
{
  int u,v,k,i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j] = 0;
    }
  }

  for(i=0;i<n;i++)
    {
      scanf("%d %d",&u,&k);
      u--;
      for(j=0;j<k;j++)
	{
	  scanf("%d",&v);
	  v--;
	  M[u][v] = 1;
	}
    }

  dfs();

  return 0;
}


void dfs()
{
  int u;
  for(u=0;u<n;u++)
    {
      color[u] = WHITE;
    }
  time = 0;
  for(u=0;u<n;u++)
    {
      if(color[u] == WHITE)
	  visit(u); 
    }
  for(u=0;u<n;u++)
    {
      printf("%d %d %d\n",u+1,d[u],f[u]);
    }
}




void visit(int u){
  int v;
  color[u] = GRAY;
  d[u] = ++time;
  for(v=0;v<n;v++)
    {
      if(M[u][v] == 0)continue;
      if(color[v] == WHITE)
	{
	  visit(v);
	}
    }
  color[u] = BLACK;
  f[u] = ++time;
}

