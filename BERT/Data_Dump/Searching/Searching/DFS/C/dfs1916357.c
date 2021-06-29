#include<stdio.h>
#define N 105
#define WHITE 0
#define GRAY 1
#define BLACK 2

int d[N],f[N];
int n;
int color[N],t,a[N][N];

void dfs();
void visit(int);

int main(){
  int id,v,k;
  int i,j;

  scanf("%d",&n);
  for(i=1; i <= n; i++){
    for(j=1; j <=n; j++){
      d[i]=0;
      f[i]=0;
    a[i][j]=0;
  }
  }

 for(i=1; i <= n; i++){
    scanf("%d%d",&id,&k);
    for(j=1; j <=k; j++){
      scanf("%d",&v);
      a[id][v]=1;
    }
  }
    dfs();

  return 0;
}

void dfs(){
  int i;

  for(i=1; i <=n; i++){
    color[i]=WHITE;
  }
  t=0;
  for(i=1; i <=n; i++){
    if(color[i]==WHITE) visit(i);
  }
  for(i=1; i <=n; i++){
    printf("%d %d %d\n",i,d[i],f[i]);
}
}

void visit(int u){
  int i;
  color[u]=GRAY;
  d[u]=++t;
  for(i=1; i <= n; i++){
    if(a[u][i]==0) continue;
      if(color[i]==WHITE){
	visit(i);
      }
  }
      color[u]=BLACK;
      f[u]=++t;
}
