#include<stdio.h>
#define MAX 101
#define WHITE -1
#define GRAY -2
#define BLACK -3

int G[MAX][MAX],d[MAX],color[MAX];
int n,k[MAX],u,v,time;
int head,tail;
int Q[MAX];

int empty(){
  if(head==tail) return 1;
  else return 0;
}

void Enqueue(int x){
  Q[tail] = x;
  
  if(tail==MAX) tail = 0;
  else tail += 1;
  
}

int Dequeue(){
  int x;
  x = Q[head];
  
  if(head == MAX) head = 0;
  else head += 1;
  
  return x;
}


void BFS(int s){
  int i,j;

  for(u=1; u<=n; u++){
    color[u] = WHITE;
  }
  d[s] = 0;
  Enqueue(s);
  while(!empty()){
    u = Dequeue();
    for(i=1; i<=k[u]; i++){
      if(color[G[u][i]] == WHITE){
	color[G[u][i]] = GRAY;
	d[G[u][i]] = d[u]+1;
	Enqueue(G[u][i]);
      }
    }
    color[u] = BLACK;
  }
}
  
int main(){
  int i,j;
  
  scanf("%d",&n);
  
  for(i=1; i<=n; i++){
    scanf("%d%d",&u,&k[i]);
    d[u] = -1;
    for(j=1; j<=k[i]; j++){
      scanf("%d",&G[i][j]);
    }
  } 
  BFS(1);

  for(i=1; i<=n; i++){
    printf("%d %d\n",i,d[i]);
  }

  return 0;
}
