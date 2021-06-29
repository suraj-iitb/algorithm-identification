#include<stdio.h>
#define M 100

#define W -3
#define B -4
#define G -2

void Dfs();
void Dfsv(int );

int d[M];
int f[M];
int color[M];
int time;
int Adj[M][M];//有向グラフGの隣接リスト
int n;


main () {

  int i, j;//counter
  int a, b, c;

  scanf("%d", &n);

  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      Adj[i][j] = 0;//隣接リストの初期化   
    }  
  }

  for(i = 0; i < n; i++) {
    scanf("%d", &a);
    scanf("%d", &b);
    for(j = 0; j < b; j++) {
      scanf("%d", &c);    
      Adj[i][c-1] = 1;
    }

  }

  Dfs();

  for(i = 0; i < n; i++) {
    printf("%d %d %d\n", i+1, d[i], f[i]);  
  }

  return 0;
}


void Dfs() {
  int k;

  for(k = 0; k < n; k++) {
    color[k] = W;
  }    

  time = 0;
  
  for(k = 0; k < n; k++) {
    if(color[k] == W){
      Dfsv(k);	
    }
  }
}

void Dfsv(int u) {
  int v;

  color[u] = G;
  time++;
  d[u] = time;

  for(v = 0; v < n; v++) {
    if(Adj[u][v] && color[v] == W)
      Dfsv(v);
  }

  color[u] = B;
  f[u] = ++time;

}
