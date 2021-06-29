/*
深さ優先探索
再帰による深さ優先探索

入力例
6
1 2 2 3
2 2 3 4
3 1 5
4 1 6
5 1 6
6 0

出力例
1 1 12
2 2 11
3 3 8
4 9 10
5 4 7
6 5 6

*/

#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[N][N];
int color[N], d[N], f[N], tt;

void dfs_visit(int u){
  int v;
  color[u] = GRAY;
  d[u] = ++tt;
  for(v=0;v<n;v++){
    if(M[u][v] == 0) continue;
    if(color[v] == WHITE) { dfs_visit(v); }
  }
  color[u] = BLACK;
  f[u] = ++tt;
}

void dfs(){
    int u;
    
    for(u=0;u<n;u++) color[u] = WHITE;
    tt = 0;
    
    for(u=0;u<n;u++) if(color[u] == WHITE) dfs_visit(u); 
    for(u=0;u<n;u++) printf("%d %d %d\n", u+1, d[u], f[u]);
}

int main(){
    int u, v, k, i, j;
    
    scanf("%d", &n);
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) M[i][j] = 0;
    
    for(int i=0;i<n;i++){
        scanf("%d %d", &u, &k);
        u--;
        for(int j=0;j<k;j++){
            scanf("%d", &v);
            v--;
            M[u][v] = 1;
        }
    }
    
    dfs();
    
    return 0;
}
