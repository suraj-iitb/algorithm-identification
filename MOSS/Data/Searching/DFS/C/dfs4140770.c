#include <stdio.h>

int ANS[110][110],d[110],f[110],t=1;

void DFS(int i)
{
  int j;
  if(d[i]==0)
    {
      d[i]=t;
      t++;
      for(j=1;ANS[i][j]!=-1;j++) if(d[ANS[i][j]]==0) DFS(ANS[i][j]);
      f[i]=t;
      t++;
    }
}


int main()
{
  int j=0,i=0,n=0,k=0,u=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    {
      scanf("%d%d",&u,&k);
      for(j=1;j<=k;j++) scanf("%d",&ANS[i][j]);
      ANS[i][j]=-1;
    }
  for(i=1;i<=n;i++) DFS(i);
  for(i=1;i<=n;i++) printf("%d %d %d\n",i,d[i],f[i]);
  return 0;
}

