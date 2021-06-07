#include<stdio.h>
#define GRAY 2
#define N 101
 
int color[N],d[N],f[N],e[N],count,A[N][N],v[N],B[N][N];

void DFE_Visit(int);
void DFS(int);

main(){
  int n,i,j,v1;

  for(i=0;i<N;i++){ //行列を０で初期化
    for(j=0;j<N;j++){
      A[i][j]=0;
    }
  }
 
  scanf("%d",&n);
   
  for(i=1;i<=n;i++){
    scanf("%d%d",&v[i],&e[i]);
    for(j=1;j<=e[i];j++){
      scanf("%d",&v1);
      B[i][j]=v1; //Bのi行j列に値を容れる
      A[i][v1]=1; //Aにフラグを建てる
    }
  }
  DFS(n);
 
  return 0;
}


void DFS(int n){
  int i,u;
   
  for(i=1;i<=n;i++){ //実質的にcolorを０に初期化
    u=v[i];
    color[u]=0;
  }

    count=0;
   
  for(i=1;i<=n;i++){ //実質的にi回DFEを呼び出し、かつプリント
    u=v[i];
    if(color[u]==0)DFE_Visit(u);
    printf("%d %d %d\n",u,d[u],f[u]);
  }
}


void DFE_Visit(int u){
  int v,i;
   
  color[u]=GRAY; //未確定で初期化
  d[u]=++count;
 
  for(i=1;i<=e[u];i++){ //Bの値を順番に呼び出して再帰することによってd[u]の値を決定する
    v=B[u][i];
    if(color[v]==0)DFE_Visit(v);
  }
  color[u]=1;
  f[u]=++count; //再帰の特徴から、逆順に入る
}
