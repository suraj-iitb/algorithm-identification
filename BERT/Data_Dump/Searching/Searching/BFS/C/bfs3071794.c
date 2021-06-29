#include <stdio.h>
#include <stdlib.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INFTY 1<<21
#define N 1001
int head=1;
int tail=1;
int n;
int d[N];
int M[N][N];
int color[N];
int Q[N];
void dfs(int);
void enqueue(int);

int main(){
  int i,j,v,k,c,u;

  scanf("%d",&n);
  
  for(i=0;i<N;i++){
    Q[i] = -1;
    for(j=0; j<N; j++){
      M[i][j] = INFTY;
    }
  }
  
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v] = 1;
    }
  }
  // printf("debug\n");
  dfs(0);

  return 0;
}

void dfs(int s){
  int i,u,v;
  for(i=0; i<n; i++){
    d[i] = INFTY;
    color[i] = WHITE;
  }
  d[s] = 0;
  color[s] = GRAY;
  enqueue(s);

  while(1){
   
 
    if( tail == head) break;
       u = dequeue();
    for(v = 0; v <n; v++){
      if(M[u][v] != INFTY && color[v] != BLACK &&d[v]==INFTY){
	color[v] = GRAY;
	d[v] = d[u] + 1;
	enqueue(v);
	}
    }
    color[u] = BLACK;

  }
  
  for(i = 0; i<n; i++){
    printf("%d %d\n",i+1,((d[i]==INFTY) ? (-1) : d[i]));
  }
}

void enqueue(int s){
  Q[tail++] = s;
}
int dequeue(){
  int r = Q[head++];
  return r;
}

