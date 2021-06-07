#include <stdio.h>

void visit(int);
int n,adj[101][101],d[101],f[101],time;
char color[101];
int main(){  
  int i,j,a,b;
  scanf("%d",&n);
 
  for(i=1;i<=n;i++) {
    scanf("%d%d",&a,&b);    
    for(j=1;j<=b;j++)
      scanf("%d",&adj[a][j]);
  }

  for(i=1;i<=n;i++) 
    color[i] = 'W';
  time = 0;
  for (i=1;i<=n;i++) 
    if (color[i] == 'W')
      visit(i);
  for(i=1;i<=n;i++)
    printf("%d %d %d\n",i,d[i],f[i]);

  return 0;
}


void visit(int u){

  int i,v;
  color[u] = 'G' ;
  d[u] = ++time;
  for(i=1;i<=n;i++){
    if(adj[u][i]!=0){
      v=adj[u][i];
      if (color[v] == 'W')
	visit(v);

    }
  }
  color[u] = 'B'; 
  f[u] = ++time;

}
