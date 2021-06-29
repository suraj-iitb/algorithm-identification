#include <stdio.h>

typedef struct ver{
  int e[101];
  int se;
  int color;
} ver;
   
int n,u;
int time;
int a[101];
int b[101];
ver c[101];
 
void visit(int u){

  int v,w;

  c[u].color=1;
  a[u] = ++time;

  for(v=1;v<=c[u].se;v++){
    w=c[u].e[v];
    if(c[w].color == 0){
      visit(w);
    }

  }

  c[u].color = 2;
  b[u] = ++time;

}
 
void dfs(){

  int u;

  for(u=1;u<=n;u++){
    c[u].color = 0;
  }

  time = 0;

  for(u=1;u<=n;u++){
    if(c[u].color==0){
      visit(u);
    }

  }
}
 
 
 
 
int main(){

  int i,j,k,v;
 
  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    c[u].se=k;
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      c[u].e[j]=v;
    }
  }
 
  dfs();
 
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,a[i],b[i]);
  }
   
  return 0;
}
