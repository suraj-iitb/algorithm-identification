#include<stdio.h>
#include<limits.h>
  
#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2
  
int Q[N], M[N][N], color[N], d[N], n, f=1, c=1;
  
void Enqueue(int n){
  Q[f] = n;
  f++;
  if(f == N) f=1;
}
  
int Dequeue(){
  int x = c;
  c++;
  if(c == N) c=1;
  return Q[x];
}
  
void BFS(int s){
  int i, u;
  for(i = 1; i <= n; i++){
    color[i] = WHITE;
    d[i] = -1;
  }
  color[s] = GRAY;
  d[s] = 0;
  Enqueue(s);
  while(f != c){
    u = Dequeue();
    for(i = 1; i <= n; i++){
      if(color[i] == WHITE && M[u][i] == 1){
    color[i] = GRAY;
    d[i] = d[u] + 1;
    Enqueue(i);
      }
    }
    color[u] = BLACK;
  }
}
  
int main(){
  int i, j, k, x, s, m;
  for(i=1; i < n; i++){
    for(j=1; j < n; j++) M[i][j] = 0;
  }
  scanf("%d",&n);
  for(i=1; i <= n; i++){
    scanf("%d%d", &m, &k);
    if(i == 1) s = 1;
    for(j=0; j < k; j++){
      scanf("%d",&x);
      M[m][x] = 1;
    }
  }
  BFS(s);
  for(i=1; i <= n; i++){
    printf("%d %d\n", i, d[i]);
  }
  return 0;
}
