#include<stdio.h>
#define w 0
#define g 1
#define b 2
int a[101][101];
int n,color[101],d[101],f[101],tt;
void dfs_v(int u)
{  int v;
   color[u]=g;
   d[u]=++tt;
   for(v=0;v<n;v++)
   {  if(a[u][v]==0)  continue;
      if(color[v]==w) dfs_v(v);
   }
   color[u]=b;
   f[u]=++tt;
}
void dfs()
{  int u;
   for(u=0;u<n;u++)  color[u]=w;
   tt=0;
   for(u=0;u<n;u++)
     if(color[u]==w)  dfs_v(u);
   for(u=0;u<n;u++)
     printf("%d %d %d\n",u+1,d[u],f[u]);
}
int main()
{  int i,t,k,p,j,u;
   scanf("%d",&n);
   k=n;
   for(i=0;i<n;i++)
     for(j=0;j<n;j++)
       a[i][j]=0;
   while(k)
   {  scanf("%d%d",&t,&p);
      t=t-1;
      for(i=0;i<p;i++)
      {  scanf("%d",&u);
         u=u-1;
         a[t][u]=1;
      }
      k--;
   }
   dfs();
}
