#include <stdio.h>

#define N 100
#define WHITE -1
#define GRAY -2
#define BLACK -3

void PrintFunction(void);
void initialize(void);
void visit(int);
void dfs(void);

int n;
int Adj[N][N];
int color[N];
int D[N],F[N];
int time;


int main(){
  int i,j,k;
  int u,v;
  
  initialize();
  scanf("%d",&n);

    for(i = 0;i < n;i++){
      scanf("%d %d",&u, &k);
      u--;
      for(j = 0;j < k;j++){
        scanf("%d",&v);
        v--;
	  Adj[u][v] = 1;
         }
	    }
  dfs();

  PrintFunction();
  return 0;
}

void PrintFunction(){
  int i;
   for(i = 0;i < n;i++) 
    printf("%d %d %d\n",i+1,D[i],F[i]);
  
}

void initialize(){
  int i,j;

  for(i = 0;i < N;i++){
    for(j = 0;j < N;j++){
      Adj[i][j] = 0;
    }
  }
}

void dfs(){
  int u;

  for(u = 0;u < n;u++)
    color[u] = WHITE;
    time = 0;


  for(u = 0;u < n;u++){
    if(color[u] == WHITE) visit(u);
  }
}

void visit(int u){
  int v;
  color[u] = GRAY;
  D[u] = ++time;
  for(v = 0;v < n;v++){
    if(Adj[u][v] == 0) continue;
    if(color[v]  == WHITE){
      visit(v);

    }
  }
    color[u] = BLACK;
  F[u] = ++time;
}

