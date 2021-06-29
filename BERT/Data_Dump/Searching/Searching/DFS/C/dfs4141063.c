#include<stdio.h>

int V[101][101]={0};
int d[101]; // 発見時刻
int f[101]; // 完了時刻
int time=0;

void dfs(int,int);

int main()
{
  int i,j;
  int n,u,k,v;
 
  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf("%d%d",&u,&k);
      for(j=0;j<k;j++)
	{
	  scanf("%d",&v);
	  V[u][v]=1;
	}
    }

  for(i=0;i<n;i++)
    {
    if(d[i+1]==0) dfs(i+1,n);
    }

  for(i=0;i<n;i++)
    {
      printf("%d %d %d\n",i+1,d[i+1],f[i+1]);
    }

  return 0;
}

void dfs(int i, int n)
{
  int j;
  d[i] = ++time;
  for(j=0;j<n;j++){
    if(V[i][j+1] != 1) continue;
    else V[i][j+1] = 0;
    
    if(d[j+1] == 0) dfs(j+1, n); // 再起
  }
  f[i] = ++time;
}

