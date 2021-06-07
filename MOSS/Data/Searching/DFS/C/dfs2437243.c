#include<stdio.h>
#define gray 1
#define white 0
#define black 2
#define MAX 101

int a[MAX][MAX],f[MAX],d[MAX],color[MAX],time,n;

void visit(int u)
{
  int i;
  color[u]=gray;
  d[u]=++time;
  for(i=0;i<n;i++){
    if(a[u][i]==1){
      if(color[i]==0)visit(i);
    }
  }
  color[u]=black;
  f[u]=++time;
}


int main()
{
  int i,j,v,u,k;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    color[i]=white;
  }

  time=0;
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      a[u-1][v-1]=1;
    }
  }

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(a[i][j] == NULL)a[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    if(color[i]==white)visit(i);
  }

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}
