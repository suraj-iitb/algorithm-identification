#include<stdio.h>
#define N 100

int n,a[N][N],d[N],f[N],color[N];

int dfs_init(){
    for(int i;i<n;i++)
        color[i]=d[i]=f[i]=0;
}

void dfs(int u){
    static int t=0;
    color[u]=1;
    d[u]=++t;
    for(int v=0;v<n;v++){
        if(a[u][v] && color[v]==0) dfs(v);
    }
    color[u]=2;
    f[u]=++t;
}

int main(){
  int i,j,v,k;
  scanf("%d",&n);
  int u[n];
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)a[i][j]=0;

  for(i=0;i<n;i++){
    scanf("%d %d",&u[i],&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      a[i][v-1]=1;
    }
  }
  /*for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(j!=0) printf(" %d",a[i][j]);
      else     printf("%d",a[i][j]);
    }
    printf("\n");
  }
  
  printf("\n");*/
  
  
  dfs_init();
  for(i=0;i<n;i++)
      if(!color[i]) dfs(u[i]-1);
  
  for(i=0;i<n;i++) printf("%d %d %d\n",u[i],d[i],f[i]);
  
  return 0;
}
