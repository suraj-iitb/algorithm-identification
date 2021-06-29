#include<stdio.h>
#define WH 10
#define BL 20
#define GR 30

int a[101][101],d[101],f[101],color[101];
int time,n;
void dfs();
void visit(int);

int main()
{
  int k,i,j,v,u;

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
    color[i]=WH;
  time = 0;
  for( i=1 ; i<=n ; i++)
  {  
    if(color[i]==WH) visit(i);
  }    
}

void visit(int u)
{
  int i;
  color[u]=GR;
  time++;
  d[u]=time;
  for( i=1 ; i<=n ; i++)
  {  
    if(a[u][i]==1)
    {
      if( color[i]==WH )
	visit(i);
    }  
  }
  color[u]=BL;
  time++;
  f[u]=time;
}

