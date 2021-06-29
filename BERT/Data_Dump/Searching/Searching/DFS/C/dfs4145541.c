#include <stdio.h>
#define N 105
#define WHITE 0
#define BLACK 1
#define GRAY 2
void visit(int);
void dfs();
int time,n;
int M[N][N],color[N],d[N],f[N];

int main()
{
  int a,b,c,i,j;
  
  scanf("%d",&n);   //頂点数
  for (i=1;i<=n;i++){
    for (j=1;j<=n;j++){
      M[i][j] = 0;
    }
  }
  for (i=1;i<=n;i++){
    scanf("%d%d",&a,&b);    //頂点の番号,aの出次数
    for (j=1;j<=b;j++){
      scanf("%d",&c);       //aに隣接する頂点の番号
      M[a][c] = 1;
    }  
  }
  dfs();
  for (i=1;i<=n;i++)
    printf("%d %d %d\n",i,d[i],f[i]);

  return 0;
}

 

void visit(int r){
  int i;
  
  color[r]=GRAY;
  d[r]=++time;
  
  for(i=1;i<=n;i++){
    if(M[r][i]==WHITE)
      continue;
    if(color[i]==WHITE)  //通れない
      visit(i);
  }
  color[r]=BLACK;
  f[r]=++time;
}


void dfs(void){
  int j;
  for(j=1;j<=n;j++){
    color[j]=WHITE;  //初期化
  }
  time=0;

  for(j=1;j<=n;j++){   //黒になるまでまわす
    if(color[j]==WHITE)
      visit(j);
  }
}
  

