#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
  
#define N 101
#define WHITE 0
#define BLACK 1
#define GRAY 2
  
int n,head=1,tail=1,adj[N][N],color[N],d[N],Q[N];
  
int Queemp(){
  if(head == tail){
    return 1;
  }
 else{
    return 0;
  }
}
 
 
void Enque(int r){
  int i;
  Q[tail] = r;
  tail++;
}
 
 
int Deque(void){
  int i;
  i = Q[head];
  Q[head] = -1;
  head++;
  return i;
}
 
 
void bfs(int s){
  int u,v;
  color[s] = GRAY;
  d[s] = 0;
  Enque(s);
  while(Queemp() == 0){
    u = Deque();
    for(v=1;v<=n;v++){
      if(color[v] == WHITE && adj[u][v] == 1){
    color[v] = GRAY;
    d[v] = d[u] + 1;
    Enque(v);
      }
    }
    color[u] = BLACK;
  }
}
 
 
int main(void) {
  int i,j,k,u,v;
 
  for(i=1;i<N;i++){
    for(j=1;j<N;j++){
      adj[i][j] = 0;
    }
    Q[i] = -1;
    color[i] = WHITE;
    d[i] = INT_MAX;
  }
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d %d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      adj[u][v] = 1;
    }
  }
  bfs(1);
  for(i=1;i<=n;i++){
    if(d[i] == INT_MAX){
      d[i] = -1;
    }
    printf("%d %d\n",i,d[i]);
  }
  return 0;
}
