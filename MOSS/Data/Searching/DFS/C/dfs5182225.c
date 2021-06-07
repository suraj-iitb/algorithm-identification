/*
nodeの値が小さいところを選択して総渡していくプログラム
過程で最初に触れた時と、最後に触れた時をタイムスタンプという

入力　隣接行列を作る時と同じ入力方法
　　　頂点　個数　頂点１　頂点２...

出力　頂点　最初　最後
　　　　....
 */

#include<stdio.h>
#define N 100
#define WHITE 0 // 探索末
#define GRAY 1  // 探索中
#define BLACK 2 // 探索済

void dfs_vis(int);
void dfs();

int n,m[N][N];
int c[N],d[N],f[N],g;

int main()
{
  int i,j,a,b,c;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++) m[i][j]=0;
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&a,&b);
    a--;
    for(j=0;j<b;j++){
      scanf("%d",&c);
      c--;
      m[a][c]=1;
    }
  }
  dfs();
  return 0;
}
void dfs(){
  int i;
  for(i=0;i<n;i++) c[i]=WHITE;
  g=0;
  for(i=0;i<n;i++){
    if(c[i]==WHITE) dfs_vis(i);
  }
  for(i=0;i<n;i++) printf("%d %d %d\n",i+1,d[i],f[i]);
}
void dfs_vis(int i){
  int x;
  c[i]=GRAY;
  d[i]=++g;
  for(x=0;x<n;x++){
    if(m[i][x]==0) continue;
    if(c[x] == WHITE) dfs_vis(x);
  }
  c[i]=BLACK;
  f[i]=++g;
}
  
  

