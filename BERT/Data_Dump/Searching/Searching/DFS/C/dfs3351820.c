#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
int color[101];
int A[101][101];
int d[101];
int f[101];
int time,n;
void dfs(void);
void visit(int);
int main(){
  int i,j,k,id,kn;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&id,&kn);
    for(j=0;j<kn;j++){
      scanf("%d",&k);
      A[id][k]=1;
    }
  }
  dfs();
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}
void dfs (void){
  int i,j;
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      if(A[i][j]==1){
	if(color[i]==WHITE){
	  visit(i);
	}
      }
    }
  }
}
void visit(int u){
  int i;
  color[u]=GRAY;
  d[u]=++time;
  for(i=1;i<=n;i++){
    if(A[u][i]==1){
      if(color[i]==WHITE){
	visit(i);
      }
    }
  }
  color[u]=BLACK;
  f[u]=++time;
}
      
    
  
  
 

