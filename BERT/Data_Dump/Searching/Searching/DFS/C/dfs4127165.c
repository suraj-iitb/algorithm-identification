#include <stdio.h>
#define N 100

void dfs(void);
void visit(int);

int n,a[N][N],color[N],t,d[N],f[N]; //d=start,f=finish

int main(){
  int i,j,k,x,u;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    for(j = 0;j < n;j++){
      a[i][j] = 0;
    }
  }
  for(i = 0;i < n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j = 0;j < k;j++){ //x=連結
      scanf("%d",&x);
      x--;
      a[u][x] = 1;
    }
  }

  dfs();

  for(i = 0;i < n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
 
  return 0;
}

void dfs(void){
  int u;
  for(u = 0;u < n;u++){
    color[u] = 0; //0=白（未到達）
  }
  t = 0;
  for(u = 0;u < n;u++){
    if(color[u] == 0) visit(u);
  }
}

void visit(int r){
  int i;
  color[r] = 1; //1=灰（到達地点）
  d[r] = ++t;
  for(i = 0;i < n;i++){
    if(a[r][i] == 0) continue; //つながっていないから
    if(color[i] == 0) visit(i);
  }
  color[i] = 2; //2=黒（いきどまり）
  f[r] = ++t;
}

