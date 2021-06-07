#include <stdio.h>
#define GRAY  2 
#define WHITE 0
#define BLACK 1 

int n,color[110],d[110],f[110],time,adj[110][110];
void visit(int u){
int i;
color[u]=GRAY;
d[u]=++time;
 for(i=1;i<=n;i++){
   if(adj[u][i]==1){
     if(color[i]==WHITE) visit(i);
   }
 }
 color[u]=BLACK;
 f[u]=++time;

}
void dfs(int u){
  int i;
  for(i=1;i<=n;i++){
  color[i]=WHITE;
  time=0;
  }
  for(i=1;i<=n;i++){
    if(color[i]==WHITE) visit(i);
  }
}



int main(){

  int u,k,v,i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      adj[u][v]=1;
    }
    dfs(u);
  }

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;



}
