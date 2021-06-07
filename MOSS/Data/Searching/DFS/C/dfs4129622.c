#include<stdio.h>
#define MAX 100
#define WHITE 1
#define GREY 2
#define BLACK 3
#define NIL -1

int M[MAX][MAX],c[MAX],d[MAX],f[MAX],ts,n;

void dfs(int u){
  int i;
  d[u]=++ts;
  c[u]=GREY;
  for(i=0;i<n;i++){
    if(M[u][i]==1&&c[i]==WHITE) dfs(i);
  }
  
  f[u]=++ts;
  c[u]=BLACK;
}

void DFS(){
  int i;
  for(i=0;i<n;i++){
    c[i]=WHITE;
  }
  ts=0;
  for(i=0;i<n;i++){
    if(c[i]==WHITE) dfs(i);
  }
}

int main(){
  int i,j,u,k,l;
  scanf("%d",&n);

  for(i=0;i<n;i++)
    for(j=0;j<n;j++) M[i][j]=0;

  for(i=0;i<n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&l);
      M[u-1][l-1]=1;
    }
  }
  DFS();
  /*for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(j>0) printf(" ");
      printf("%d",M[i][j]);
    }
    printf("\n");
    }*/
  for(i=0;i<n;i++) printf("%d %d %d\n",i+1,d[i],f[i]);
  return 0;
}

