#include <stdio.h>
#include <string.h>
typedef struct {int d,f;}Time;
Time S[101];
int Adj[101][101],n,tokei=0;
void DFS();
void N(int);
int main(){
  int v,i,j,u,k;
  memset(Adj, 0, 101*101*sizeof(int));
  memset(S, 0, 101*sizeof(Time));
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      Adj[u][v]=1;
    }
  }

  DFS();

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,S[i].d,S[i].f);
  }
  return 0;
}
void DFS(){
  int i;
  for(i=1;i<=n;i++){
    N(i);
  }
}
void N (int i){
  int k;
  if(S[i].d!=0)return;
  tokei++;
  S[i].d=tokei;
  for(k=1;k<=n;k++){
    if(Adj[i][k]==1)
      N(k);
  }
  tokei++;
  S[i].f=tokei;
}
	   

