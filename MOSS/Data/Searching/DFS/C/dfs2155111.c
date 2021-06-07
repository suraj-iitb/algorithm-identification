#include <stdio.h>
  
int walk(int i, int time, int w[101][101], int *d, int *f)
{
  int *p;
  
  d[i] = ++time;
  for (p = w[i]; *p != 0; p++)
    if (!d[*p])
      time = walk(*p, time, w, d, f);
  f[i] = ++time;

  return time;
}
  
int main(void)
{
  int num;
  int i,j;
  int u,k;
  int tm=0;
  int d[101]={};
  int f[101]={};
  int w[101][101]={};
  
  scanf("%d", &num);
  for (i=0;i<num;i++)
    {
      scanf("%d %d",&u,&k);
      for (j=0;j<k;j++)
	scanf("%d",&w[u][j]);
    }
  
  for (i=1;i<=num;i++)
    if (d[i]==0)
      tm=walk(i,tm,w,d,f);
  
  for (i=1;i<=num;i++)
    printf("%d %d %d\n",i,d[i],f[i]);
  
  return 0;
}
