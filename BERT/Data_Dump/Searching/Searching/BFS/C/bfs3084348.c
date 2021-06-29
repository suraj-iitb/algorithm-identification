#include<stdio.h>

 
#define N 101
#define BLACK 2
#define WHITE 0
#define GRAY  1
 
 
 
int n=0;
//int z=0;
int G[N][N];
int d[N];
//int f[N];
int color[N];
int que[N];
int head=WHITE;
int tail=WHITE;
 
void Enqueue(int s){
  que[tail] = s;
  tail++;
}
 
int Dequeue(){
  int y;
  y = que[head];
  head+=1;
  return y;
} 
   
 
void bfs(int s){
  int u,w;
  for(u=1;u<=n;u++){
    color[u] = WHITE;
    d[u] = -1;
  }
  color[s] = GRAY;
  d[s] = 0;
  Enqueue(s);
  while(head != tail){
    u = Dequeue();
    for(w=1;w<=n;w++){
      if(color[w] == WHITE && G[u][w] == GRAY){
        color[w] = GRAY;
        d[w] = d[u] + 1;
        Enqueue(w);
      }
    }
    color[u] = BLACK;
  }
}
 
 
 
main(){
  int i,j,s,v,r;
  int p = 1;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1; j<=n;j++){
      G[i][j] = 0;
    }
  }
  for(i=1;i<=n;i++){
    scanf("%d%d", &v,&r);
    for(j=1;j<=r;j++){
      scanf("%d",&s);
      G[i][s] = 1;
    }
  }
  bfs(p);
  for(i=1;i<=n;i++){
    printf("%d %d\n",i, d[i]);
  }
  return 0;
}

