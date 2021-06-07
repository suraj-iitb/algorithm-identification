#include<stdio.h>
#define MAX 102
#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs(int);
void visit(int,int);
void print(int);

int A[MAX][MAX],d[MAX],f[MAX],color[MAX],time;
int main(){
  int n,m,i,j,flag=0,k;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d %d",&A[i][0],&m);
    for(j=1;j<=m;j++){
      flag = scanf("%d",&k);
      if(flag==1) A[i][k]=1;
      flag=0;
    }
  }
  dfs(n);
  print(n);
  return 0;
}
void dfs(int n){
  int i;
  for(i=1;i<=n;i++){
    if(color[i]==WHITE) visit(i,n);
  }
}
void visit(int u,int n){
  int i;
  color[u]=GRAY;
  d[u]=++time;
  for(i=1;i<=n;i++){
    if(A[u][i]==0) continue;
    if(color[i]==WHITE) visit(i,n);
    }
  color[u]=BLACK;
  f[u]=++time;
}
void print(int n){
  int i;
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
}


