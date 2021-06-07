#include <stdio.h>

int n,time,v[100][100],a[100],d[100],f[100]; 

void visit(int);

void dfs()
{
  int u;
  for(u=0;u<n;u++)
    {
      a[u]=0;
      time=0;
    }
  for(u=0;u<n;u++)
    {
      if(a[u]==0){visit(u);}
    }
  for(u=0;u<n;u++)
    {
      printf("%d %d %d\n",u+1,d[u],f[u]);
    }
}

void visit(int u)
{
  int b;
  a[u]=1;
  d[u]=++time;
  for(b=0;b<n;b++)
    {
      if(v[u][b]==0)continue;
      if(a[b]==0){visit(b);}
    }
  a[u]=2;
  f[u]=++time;

}


int main()
{
  int i,j,u,k,a;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
	 {
	   v[i][j]=0;
	 }
    }
  
  for(i=0;i<n;i++)
  {
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++)
      {
        scanf("%d",&a);
	a--;
	v[u][a]=1;
      }
  }

  dfs();

  return 0;
}
  

