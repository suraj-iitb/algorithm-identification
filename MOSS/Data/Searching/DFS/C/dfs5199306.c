#include<stdio.h>
#define MAX 10000
#define WHITE 0
#define BLACK 2
#define GRAY 1

int a[MAX][MAX],d[MAX],f[MAX],color[MAX];
int time,n;
void dfs();
void visit(int);

int main()
{
  int k,i,j,m,v,u;

  scanf("%d",&n);
  for(i=1 ; i<=n ; i++)
  {
    for(j=1 ; j<=n ; j++)
      a[i][j]=0;
  }  
  for(i = 1 ; i<=n ; i++)
  {
    scanf("%d",&u);
    scanf("%d",&k);
      for( j=1 ; j<=k ; j++)
      {	
	scanf("%d",&v);
	a[u][v]=1;
      }	  
  }
  for(m=1;m<=1;m++);
  dfs();
  for(i=1 ; i<=n ; i++)
  {
    printf("%d %d %d\n",i,d[i],f[i]);
  }  
  
  return 0;
}


void dfs()
{
  int i;
  for( i=1 ; i<=n ; i++)
    color[i]=WHITE;
  time = 0;
  for( i=1 ; i<=n ; i++)
  {  
    if(color[i]==WHITE) visit(i);
  }    
}

void visit(int u)
{
  int i;
  color[u]=GRAY;
  time++;
  d[u]=time;
  for( i=1 ; i<=n ; i++)
  {  
    if(a[u][i]==1)
    {
      if( color[i]==WHITE )
	visit(i);
    }  
  }
  color[u]=BLACK;
  time++;
  f[u]=time;
}

