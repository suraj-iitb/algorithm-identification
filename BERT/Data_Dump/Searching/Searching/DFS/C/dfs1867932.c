#include <stdio.h>
#define MAX 100
 
int Ryo[MAX+1][MAX+1], fat[MAX+1], d[MAX+1], f[MAX+1], t;
 
void visit(int pine){
  int i;
  d[pine] = t++;
  for(i=1;i<=fat[pine];i++) if(!d[Ryo[pine][i]]) visit(Ryo[pine][i]);
  f[pine] = t++;
}
 
main(){
  int i, j, u, v,n;
  scanf("%d", &n);
  t = 1;
  for(i=1;i<=n;i++){
    d[i] = f[i] = 0;
    scanf("%d", &u);
    scanf("%d", &fat[u]);
    for(j=1;j<=fat[u];j++) scanf("%d", &Ryo[u][j]);
  }
  for(i=1;i<=n;i++) if(!d[i]) visit(i);
  for(i=1;i<=n;i++) printf("%d %d %d\n", i, d[i], f[i]);
  return 0;
}
