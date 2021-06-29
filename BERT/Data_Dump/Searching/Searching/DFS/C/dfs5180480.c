#include <stdio.h>

void togo(int);
int island[100][100];
int A[100], B[100], color[100], time, a;

int main()
{
  int i, j, k, l, m;

  scanf("%d",&a);

  for(i=0; i<a; i++)
  {
    color[i]=0;

    for(j=0; j<a; j++)
    {
      island[i][j]=0;
    }
  }

  time=0;

  for(i=0; i<a; i++)
  {
    scanf("%d %d",&k, &l);
    for(j=0; j<l; j++)
    {
      scanf("%d",&m);
      island[k-1][m-1]=1;
    }
  }

  for(i=0; i<a; i++)
  {
    if(color[i]==0) togo(i);
    printf("%d %d %d\n",i+1, B[i], A[i]);
  }

  return 0;
}

void togo(int x)
{
  int i;
  color[x]=1;
  B[x]=++time;

  for(i=0; i<a; i++)
  {
    if(island[x][i]==1)
    {
      if(color[i]==0) togo(i);
    }
  }

  color[x]=2;
  A[x]=++time;
}
