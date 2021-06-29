#include<stdio.h>
#include<stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2


void dfs();
void visit(int);
int kill,A[101],time,T[101][2];
int me[101][101];
int main(){
  int baby,i,j,yasuna,sonya;
  scanf("%d",&kill);
  for(i=1;i<kill;i++)A[i]=WHITE;
  for(i=1;i<=kill;i++)for(j=0;j<=kill;j++)me[i][j]=0;

  for(i=0;i<kill;i++){
    scanf("%d%d",&yasuna,&sonya);
    for(j=0;j<sonya;j++){
      scanf("%d",&baby);
      me[yasuna][baby]=1;
    }
  }
  dfs(me);
  for(i=1;i<=kill;i++)printf("%d %d %d\n",i,T[i][0],T[i][1]);
}
void dfs(){
  int i;
  for(i=1;i<=kill;i++){
    if(A[i]==WHITE)visit(i);
  }
}
void visit(int u){
  int i,v;
  A[u]=GRAY;
  T[u][0]=++time;
  for(v=1;v<=kill;v++)if(me[u][v]==1)if(A[v]==WHITE)visit(v);
  A[u]=BLACK;
  T[u][1]=++time;
}

