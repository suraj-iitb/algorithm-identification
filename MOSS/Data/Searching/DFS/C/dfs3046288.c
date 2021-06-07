#include<stdio.h>
#define MAX 105
#define BLACK 0
#define WHITE 1
#define GRAY -1

void dfs();
void visit(int);

int a[MAX][MAX],n,time;
int d[MAX],f[MAX],color[MAX];

int main(){
  int i,j,m,k,l;
  

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      a[i][j]=0;
    }
  }
  
  for(i=1;i<=n;i++){
    scanf("%d%d",&m,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&l);
      a[m][l]=1;
    }
  }

  dfs();

  for(i=1;i<=n;i++){
    printf("%d %d %d",i,d[i],f[i]);
    printf("\n");
  }
  


  return 0;
}

void dfs(){
  int u;
  for(u=1;u<=n;u++){
    color[u]=WHITE;
  }
  time=0;
  for(u=1;u<=n;u++){
    if(color[u]==WHITE){
      visit(u);
    }
  }
}

void visit(int u){
  int v;
  color[u]=GRAY;
  d[u]=++time;
  for(v=1;v<=n;v++){
    if(a[u][v]==1){
      if(color[v]==WHITE){
	visit(v);
      }
    }
  }
  color[u]=BLACK;
  f[u]=++time;
}

