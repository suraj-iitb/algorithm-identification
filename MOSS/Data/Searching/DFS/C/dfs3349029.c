#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
void DFS();
void DFS_visit(int );

int color[N],d[N],f[N],time;
int n,M[100][100]; //0オリジン

int main()
{
  int u,k,v;
  int i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;  //M[0][0]=0,M[1][1]=0, ...
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u=u-1; //0オリジンへ変換
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v=v-1; //0オリジンへ変換
      M[u][v] = 1; // 辺作成
    }
  }

  DFS(); //深さ優先探索

  return 0;
}

void DFS(){
  int u,i;
  /* 初期化 */
  for(i=0;i<n;i++) color[i] = WHITE;
  time=0;
  
  for(u=0;u<n;u++){
    if(color[u] == WHITE) DFS_visit(u); //WHITE=未訪問であるから、訪問する。
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]); //頂点の番号、発見時刻、完了時刻の出力
  }
}

void DFS_visit(int u){
  int v;
  
  color[u] = GRAY; //一回訪問すると、GRAYになる。
  time++;
  d[u] = time; //発見
  for(v=0;v<n;v++){
    if(M[u][v]==0) continue;
    if(color[v]==WHITE) DFS_visit(v); //まだ一度も訪問していなかったら、再帰する。
  }
  color[u] = BLACK; //二度目の訪問で、BLACKになる。
  time++;
  f[u] = time; //完了
}

  


   
     

