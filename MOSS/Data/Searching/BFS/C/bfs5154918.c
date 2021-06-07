#include<stdio.h>
#define WH 10
#define BL 20
#define GR 30
#define INF -1;

int a[101][101],color[101],d[101],q[101];
int n;
int head,tail;

void bfs(int);
void enquee(int);

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
  bfs(1);
  for(i=1 ; i<=n ; i++)
  {
    printf("%d %d\n",i,d[i]);
  }  
  
  return 0;
}

void bfs(int s)
{
  int i,u;
  for( i=1 ; i<=n ; i++ )
  {
    color[i]=WH;
    d[i]=INF;
  }
  color[s]=GR;
  d[s]=0;
  head=0;
  tail=0;
  enquee(s);
  while( tail!=head )
  {
    u=q[head];
    if( head+1==101)
      head=0;
    else head++;
    for( i=1 ; i<=n ; i++)
    {
      if( a[u][i]==1)
      {
	if( color[i]==WH )
	{ 
	  color[i]=GR;
	  d[i]=d[u]+1;
	  enquee(i);
	}
      }	
    }  
    color[u]=BL;
  }
}

void enquee(int num)
{
  q[tail]=num;
  if( tail+1==101 )
    tail=0;
  else tail++;
}

