/*
再起による方法

dfs_init()//頂点番号は0オリジン
すべての頂点のcolorをWhiteに設定
dfs(0)

dfs(u)
 color[u] = GRAY
 d[u] = time
for(頂点vが0から|v|-1まで)
if M[u][v] && color == WHITE
dfs(v)
color[u]=BLACK
f[u]=++time
*/


#include<stdio.h>

#define N  100
#define WHITE  0
#define GRAY 1
#define BLACK 2

int n,M[N][N];
int color[N],d[N],f[N];
int t;

void dfs_visit(int u){
  int v;
   color[u]=GRAY;
  d[u] = ++t;/*最初の訪問*/

  for(v = 0;v<n;v++){
    if(M[u][v] == 0)continue;/*処理を飛ばす*/
    if(color[v] == WHITE){
        dfs_visit(v);
      }
  }
  color[u] = BLACK;
  f[u] = ++t;
}

void dfs(){
  int u;

  for(u=0;u<n;u++){
    color[u] = WHITE;
  }
  t = 0;

  for(u = 0;u<n;u++){
    if(color[u] == WHITE)dfs_visit(u);
  }

  for(u = 0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}
int main(){
  int u,k,v;
  int i,j;

  scanf("%d",&n);
  for(i = 0;i<n;i++){
    for(j = 0;j<n;j++){
      M[i][j] = 0;//リセット
    }
  }

  for(i =0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j = 0;j<k;j++){/*3 0 k= 0なのですぐはじかれる*/
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }
  
  dfs();

  return 0;
}

