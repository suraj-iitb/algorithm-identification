#include <stdio.h>

#define W -3
#define G -2
#define B -1
#define MAX 101

void dfs(void);
void visit(int);

int n;/*頂点数*/
int T[MAX][MAX];/*行＝要素、列＝繋ってる要素*/
int color[MAX];/*色分け用配列*/
int d[MAX];/*要素を最初に発見した発見時刻を記録する用配列*/
int f[MAX];/*要素の隣接リストを調べ終えた完了時刻を記録する用配列*/
int time;

int main()
{
  int i,j,youso,kazu,v;

  scanf("%d",&n);

  for(i=1;i<=n;i++)
    {
      scanf("%d%d",&youso,&kazu);

      for(j=0;j<kazu;j++)
	{
	  scanf("%d",&v);

	  T[i][v]=1;
	}
    }

  dfs();

  for(i=1;i<=n;i++)
    {
      printf("%d %d %d\n",i,d[i],f[i]);
    }
  return 0;
  
}

void dfs(void)
{
  int i;
  for(i=1;i<=n;i++)
    {
      color[i]=W;
    }
  for(i=1;i<=n;i++)
    {
      if(color[i]==W)visit(i);
    }
}
void visit(int u)
{
  int i;
  color[u]=G;
  d[u]=++time;
  for(i=1;i<=n;i++)
    {
      if(T[u][i]==1)
	{
	  if(color[i]==W)
	    {
	      visit(i);
	    }
	}
    }
  color[u]=B;
  
  f[u]=++time;
}
  

