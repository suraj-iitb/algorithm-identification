#include <stdio.h>
#define NUM 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
int m[NUM][NUM];
int n,tt;
int mark[NUM],d[NUM],f[NUM];

void search (void);
void visit (int u);
int main()
{
  int i,j,u,v,k;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  m[i][j]=0;
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
	  m[u][v] =1;
	}
    }
  search();
  return 0;
}

void search (void )
{
  
  int u;
  for(u=0;u<n;u++)
    mark[u]=WHITE;
  tt =0;

  for(u=0; u<n;u++)
    {
      if(mark[u]==WHITE) visit(u);
    }
  for(u=0;u<n;u++){
    printf("%d %d %d",u+1,d[u],f[u]);
    printf("\n");
    
  }
}
void visit (int u)
{
  int v;
  mark[u] =GRAY;
  d[u]= ++tt;
  for(v=0;v<n;v++)
    {if(m[u][v]==0)continue;
      if (mark[v] == WHITE)
	{
	  visit(v);
	}
    }
    
  mark[u] =BLACK;
  f[u] =++tt;
}
  
    

