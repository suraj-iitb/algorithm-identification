#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define O 0
#define I 1

int n,D[N][N],color[N],d[N],f[N],m;

void idfs(int);
void dfs(void);

int main(){
  int i,j,u,v,k;
  scanf("%d",&n);
  for(i=O;i<n;i++){
    for(j=O;j<n;j++){
      D[i][j]=O;
    }
  }
  for(i=O;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=O;j<k;j++){
      scanf("%d",&v);
      D[u-I][v-I]=I;
    }
  }
  dfs();
  return O;
}

void idfs(int u){
  int v;
  color[u]=GRAY;
  d[u]=++m;
  for(v=O;v<n;v++){
    if(D[u][v]==O)
      continue;
    if(color[v]==WHITE){
      idfs(v);
    }
  }
  color[u]=BLACK;
  f[u]=++m;
}

void dfs(){
  int i;
  for(i=O;i<n;i++){
    color[i]=WHITE;
  }
  m=O;
  for(i=O;i<n;i++){
    if(color[i]==WHITE){
      idfs(i);
    }
  }
  for(i=O;i<n;i++){
    printf("%d %d %d\n",i+I,d[i],f[i]);
  }
}

