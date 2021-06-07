#include<stdio.h>
#define MAX 100

int time=0,n;
int d[MAX],f[MAX];
int Graph[MAX][MAX];

void hukasa(int);


int main()
{
  int i,j,u,k,v;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&u);
    scanf("%d",&k);
    for(j=0;j<k;j++)
    {
      scanf("%d",&v);
      Graph[u-1][v-1]=1;
    }
  }
  for(i=0;i<n;i++)
  {
    if(d[i]==0) hukasa(i);
  }

  for(i=0;i<n;i++)
  {
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }

  return 0;
}

void hukasa(int i)
{
  int j;

  time++;
  d[i]=time;
  for(j=0;j<n;j++)
  {
    if(Graph[i][j]!=0 && d[j]==0) hukasa(j);
  }

  time++;
  f[i]=time;
}
