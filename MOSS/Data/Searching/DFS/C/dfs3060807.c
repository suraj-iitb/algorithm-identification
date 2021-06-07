#include<stdio.h>
#define max 100
#define White 0
#define Gray 1
#define Brack 2

int color[max],d[max],Dep[max][max]={0};
int tt,g[max];
int n;

void visit(int u){
  int i;
  color[u]=Gray;
  d[u] = ++tt;
  for(i=0;i<n;i++){
    if(Dep[u][i]==0)continue;
    if(color[i]==White){
      visit(i);
    }
  }
  color[u] = Brack;
  g[u]=++tt;
}

void dfs(){
  int i;
  for(i=0;i<n;i++){
    color[i]=White;
  }
  tt = 0;
  for(i=0;i<n;i++){
    if(color[i]==White)visit(i);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],g[i]);
  }
}

int main(){
  int u,k,num;
  int i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&num);
      num--;
      Dep[u][num]=1;
    }
  }
  dfs();
  return 0;
}
    

