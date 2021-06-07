#include<stdio.h>
#define N 200

static int a = 0;
static int b  = 1;
static int c = 2;

int n,line[N][N],node[N],d[N],f[N],t;

void linenode(int );

void lenior();

int main()
{
  int u,k,v;
  int i,j;

  scanf("%d",&n);

  for(i = 0;i < n;i++)
    {
      for(j = 0;j < n;j++)
	{
	  line[i][j] = 0;
	}
    }

  for(i = 0; i < n;i++)
    {
      scanf("%d %d",&u,&k);
      for(j = 0;j < k;j++)
	{
	  scanf("%d",&v);
	  line[u-1][v-1] = 1;
	}
    }
  lenior();

  return 0;
}
void linenode(int u)
{
  int y;
  node[u] = b;
  d[u] = ++t;
  for(y = 0;y < n;y++)
    {
      if( line[u][y] == 0)continue;
      if( node[y] == a)
	{
	  linenode(y);
	}
    }
  node[u] = c;
  t++;
  f[u] = t;
}
void lenior(){
  int i,u;
  for(i = 0;i < n;i++)
    node[i] = a;
  t = 0;
  for(u = 0;u < n;u++)
    {
      if(node[u] == a)
	    linenode(u);
    }
  for(i = 0;i < n;i++)
    {
      printf("%d %d %d\n",i+1,d[i],f[i]);
    }
}

