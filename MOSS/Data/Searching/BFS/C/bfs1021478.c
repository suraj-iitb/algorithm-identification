#include<stdio.h>
#define WHITE 1
#define BLACK 0
#define GLAY 3
#define MAX 120
#define INF -1
int n,tail,head,que[MAX],stack,g[MAX][MAX],y[MAX],z[MAX],d[MAX],color[MAX];

void Enqueue(int x){
  if(tail == MAX)
    tail = 0;
  que[tail++] = x;
} 
int Dequeue(){
  if(head == MAX)
    head = 0;
  return que[head++];
}

void BFS(int s){
  int i,u,v,t,stack,empty = 0;
  for(i = 1;i <= n; i++){
    color[i] = WHITE;
    d[i] = INF;
  }
  color[s] = GLAY;
  d[s] = 0;
  stack = empty;
  Enqueue(s);
  stack++;
  while(stack != empty){
    u = Dequeue();
    stack--;
    for(i = 1;i <= z[u];i++){
      t = g[u][i];
      if(color[t] == WHITE){
	color[t] = GLAY;
	d[t] = d[u] + 1;
	Enqueue(t);
	stack++;
      }
    }
    color[u] = BLACK;
  }
}


main(){
  int i,j;
  scanf("%d",&n);
  for(i = 1;i <= n;i++){
    scanf("%d%d",&y[i],&z[i]);
    for(j = 1; j <= z[i]; j++){
      scanf("%d",&g[y[i]][j]);
    }
  }

  BFS(y[1]);

  for(i = 1;i <= n;i++){
    printf("%d %d\n",y[i],d[y[i]]);
  }
  return 0;
}
