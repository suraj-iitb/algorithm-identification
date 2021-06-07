#include <stdio.h>

#define GRAY 0
#define WHITE 1
#define BLACK -1

typedef struct{
  int color;
  int cnt;
  int next[10];
}Node;

int d[101],f[101];
Node dfs[101];

int time;

void visit(int u){

  int i;
  // printf("now %d\n",u);
  dfs[u].color=GRAY;
  d[u]=++time;

  for(i=1;i<=dfs[u].cnt;i++){
    if(dfs[dfs[u].next[i]].color==WHITE)
      visit(dfs[u].next[i]);
  }
  dfs[u].color=BLACK;
  f[u]=++time;
  //printf("%d:(%d,%d)\n",u,d[u],f[u]);

}



int main(){

  int n,m,k,l,i,j;
  
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    dfs[i].color=WHITE;
    scanf("%d%d",&m,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&l);
      dfs[i].next[j]=l;
      dfs[i].cnt=k;
    }
  }
    
  for(i=1;i<=n;i++){
    if(dfs[i].color==WHITE)visit(i);
  }

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  


  
  return 0;
}

