#include<stdio.h>

typedef struct{
  int r[200];
}G;

G g[105];
int n,t = 0;
int d[105],f[105];
int color[105];
void visit(int i)
{
  int j;
  color[i] = 1;
  d[i] = ++t;
  for(j = 0;g[i].r[j];j++)
    {
      if(color[g[i].r[j]] == 0)visit(g[i].r[j]);
    }
  color[g[i].r[j]] = 2; 

  
  f[i] = ++t;
}

void dfs(G *g)
{
  int i;

  for(i = 1;i <= n;i++)
    {
      color[i] = 0;
    }

  for(i = 1;i <= n;i++)
    {
      if(color[i] == 0)
	{
	  visit(i);
	}
    }
}






  
int main()
{
  int i,j,k;
  int x,y,z;

  scanf("%d",&n);
  for(i = 1;i <= n;i++)
    {
      scanf("%d%d",&x,&y);
      k = 0;
      
	
      for(j = 1;j <= y;j++){
	    
	      scanf("%d",&z);
	      g[x].r[k++] = z;
      }
	}
    
  
  dfs(g);
  for(i = 1;i <= n;i++)
    {
      printf("%d %d %d\n",i,d[i],f[i]);
    }
  return 0;
}
 

