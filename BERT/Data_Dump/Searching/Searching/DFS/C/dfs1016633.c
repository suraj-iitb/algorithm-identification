#include <stdio.h>

#define N 102
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,adj[N][N],color[N],d[N],f[N],S[N],time;

int Stacktop(){
  int i;
  for (i=1;i<=n+1;i++){
    if (S[i]==-1){
      return i;
    }
  }
}

int Stackempty(){
  int i;
  for (i=1;i<=n;i++){
    if (S[i]!=-1){
      return 0;
    }
  }
  return 1;
}

void Push(int r){
  S[Stacktop()] = r;
}

void DFS_Visit(int r){
  int i,u,v;
  Push(r);
  color[r] = GRAY;
  d[r] = ++time;
  while(Stackempty()==0){
    u = S[Stacktop()-1];
    v = Nextvertex(u);
    if (v != NULL){
      if (color[v] == WHITE){
	Push(v);
	color[v] = GRAY;
	d[v] = ++time;
      }
    } else {
      Pop();
      color[u] = BLACK;
      f[u] = ++time;
    }
  }
}

void DFS(){
  int u;
  for (u=1;u<=n;u++){
    color[u] = WHITE;
    time = 0;
  }
  for (u=1;u<=n;u++){
    if (color[u] == WHITE){
      DFS_Visit(u);
    }
  }
}

int Pop(){
  int i;
  S[Stacktop()-1]= -1;
  return Stacktop()-1;
}

int Nextvertex(int v){
  int i;
  for (i=1;i<=n;i++){
    if (adj[v][i]==1 && color[i]==WHITE){
      return i;
    }
  }
  return NULL;
}

int main() {
  int i,j,u,k,v;
  //ini
  for (i=1;i<=N;i++){
    for (j=1;j<=N;j++){
      adj[i][j]=0;
    }
    S[i]=-1;
    color[i]=WHITE;
    d[i]=f[i]=0;
  }

  scanf ("%d",&n);
  for (i=1;i<=n;i++){
    scanf ("%d%d",&u,&k);
    for (j=1;j<=k;j++){
      scanf("%d",&v);
      adj[u][v]=1;
    }
  }
  DFS();

  for (i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}
