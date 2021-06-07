#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,A[100][100],color[100],d[100],f[100],time;

void visit(u){
  int v;

  color[u] = GRAY;
  d[u] = ++time;
  for(v = 0;v < n;v++){
    if(A[u][v] == 0) continue;
    if(color[v] == WHITE) visit(v);
  }
  color[u] = BLACK;
  f[u] = ++time;
}

void dfs(){
  int u;
  
  for(u = 0;u < n;u++){
    color[u] = WHITE;
  }
  time = 0;

  for(u = 0;u < n;u++){
    if(color[u] == WHITE) visit(u);
  }
  for(u = 0;u < n;u++){
    printf("%d %d %d\n",u + 1,d[u],f[u]);
  }
}



int main()
{
  int i,j,k,u,v;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    for(j = 0;j < n;j++) A[i][j] = 0;
  }

  for(i = 0;i < n;i++)
    {
      scanf("%d%d",&u,&k);
      u--;
      for(j = 0;j < k;j++)
	{
	  scanf("%d",&v);
	  v--;
	  A[u][v] = 1;
	}
    }

  dfs();

  return 0;
}

