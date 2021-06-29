#include<stdio.h>
#define White 0
#define Gray 1
#define Black 2
#define N 100

int n,a[N][N];
int color[N],d[N],f[N];//d,fはdiscoverとfinish
int count;//深さをカウント
void dfs();
void dfs_visit(int);

int main(){
  int i,j;
  int x,y,z;


  scanf("%d",&n);

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      a[i][j]=0;
    }
  }
  
  
  for(i=0; i<n; i++){
    scanf("%d %d",&x,&z);
    x--;
    for(j=0; j<z; j++){//zはx個ある隣接する頂点の個数
      scanf("%d",&y);
      y--;
      a[x][y]=1;
    }
  }

    dfs();
    return 0;
}

void dfs(){//初期化
  int x;
  for(x=0; x<n; x++){
    color[x]=White;
  }
  count=0;

  for(x=0; x<n; x++){
    if(color[x]==White) dfs_visit(x);//未探索のとき探索を行う
  }

  for(x=0; x<n; x++){
    printf("%d %d %d\n",x+1,d[x],f[x]);//x+1なのはforが0からはじまってるから
  }
}

void dfs_visit(int x){
  int y;
  color[x]=Gray;
  d[x]=++count;//先にd[x]にcountの値を入れてからインクリメント
  for(y=0; y<n; y++){
    if(a[x][y]==0) continue;//Whiteならループを中断して始めから
    if(color[y]==White){//最初にすべてのcolorがWhiteで初期化されてる。もしWhiteの場合、再帰する
      dfs_visit(y);//未探索なら再帰する
    }
  }
  color[x]=Black;
  f[x]=++count;
}

