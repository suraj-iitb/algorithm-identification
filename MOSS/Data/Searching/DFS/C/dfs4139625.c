#include <stdio.h>
#define N 100
#define NO 0
#define DISCOVERY 1
#define FINISHING 2

int n,ans[N][N];
int check[N],discover[N],finish[N],cnt;

void dfs(int u){
  int v;
  check[u]=DISCOVERY;
  discover[u]=++cnt;
  for(v=0;v<n;v++){
    if(ans[u][v]==0)continue;
    if(check[v]==NO)dfs(v);
  }
  check[u]=FINISHING;
  finish[u]=++cnt;
}
void fdfs(){
  int u;
  for(u=0;u<n;u++)check[u]=NO;
  cnt=0;
  for(u=0;u<n;u++)if(check[u]==NO)dfs(u);
  for(u=0;u<n;u++)printf("%d %d %d\n",u+1,discover[u],finish[u]);
}

int main() {
  int u,v,k;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      ans[i][j]=0;
    }
  }
  for(int i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(int j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      ans[u][v]=1;
    }
  }
  fdfs();
  return 0;
}

