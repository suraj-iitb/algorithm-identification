#include <stdio.h>
#include <stdlib.h>
#define WHITE 0
#define GRAY 2
#define BLACK 1

typedef struct
{
  int id;
  int num;
  int next[100];
}Info;

void dfs(int);
void visit(int);

Info *m;
int *d;
int *f;
int *color;
int times;
int main()
{
  int n,id,number,i,j;
  times = 0;
  scanf("%d",&n);
  d=(int *)malloc((n+1) * sizeof(int));
  f=(int *)malloc((n+1) * sizeof(int));
  m = (Info *)malloc((n+1) * sizeof(Info));
  color= (int *)malloc((n+1) * sizeof(int));

  for(i=0;i<n;i++)
    {
      scanf("%d%d",&id,&number);
      m[id].id=id;
      m[id].num=number;
      for(j=0;j<number;j++)
        scanf("%d",&m[id].next[j]);
    }

   for(i=0;i<n;i++)
    {
      d[i] = 0;
      f[i] = 0;
    }

  dfs(n);

  for(i=0;i<n;i++)
    {
      printf("%d %d %d\n",i+1,d[i+1],f[i+1]);
    }
  return 0;
}

void dfs(int n)
{
  int i;
  for(i=0;i<=n;i++)
    color[i] = WHITE;
  for(i=1;i<=n;i++)
    if(color[i] == WHITE)visit(i);
}

void visit(int i)
{
  int j;
  color[i] = GRAY;
  d[i] =++times;
  for(j=0;j<m[i].num;j++)
    if(color[m[i].next[j]] == WHITE)visit(m[i].next[j]);
  color[i] = BLACK;
  f[i] =++times;
}
