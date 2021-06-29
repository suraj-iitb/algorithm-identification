#include<stdio.h>
#define L 102
#define WHITE 1
#define BLACK 2
#define GRAY 3

int n,count,color[L],d[L],f[L],array[L][L];

void dfsv(u){
  int j;
  color[u]=GRAY;
  d[u]=++count;
  for(j=1;j<=n;j++){
    if((color[j]==WHITE) && (array[u][j]==1)){
      dfsv(j);
    }
  }
  color[u]=BLACK;
  f[u]=++count;
}

void dfs(void){
  int i;
  for(i=1;i<=n;i++){
    color[i]=WHITE;
  }
  count=0;
  for(i=1;i<=n;i++){
    if(color[i]==WHITE){
      dfsv(i);
    }
  }
}

int main(){
  int i,j,number,k,c;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      array[i][j]=0;
    }
  }
  for(i=1;i<=n;i++){
    scanf("%d%d",&number,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&c);
      array[i][c]=1;
    }
  }
  dfs();

  for(i=1;i<=n;i++) printf("%d %d %d\n",i,d[i],f[i]);
  return 0;
}
