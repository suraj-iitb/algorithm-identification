#include<stdio.h>
#define N 100
#define W 0
#define G 1
#define B 2
int n,m[N][N];
int c[N],d[N],f[N],g;
void in(){
  int a,b,c,i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      m[i][j]=0;
    }
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
}
void visit(int x){
  int y;
  c[x]=G;
  d[x]=++g;
  for(y=0;y<n;y++){
    if(m[x][y]==0)continue;
    if(c[y]==W){
      visit(y);
    }
  }
  c[x]=B;
  f[x]=++g;
}
void dfs(){
  int x;
  for(x=0;x<n;x++)c[x]=W;
  g=0;
  for(x=0;x<n;x++)if(c[x]==W)visit(x);
  for(x=0;x<n;x++)printf("%d %d %d\n",x+1,d[x],f[x]);
}
int main(){
  in();
  dfs();
  return 0;
}

