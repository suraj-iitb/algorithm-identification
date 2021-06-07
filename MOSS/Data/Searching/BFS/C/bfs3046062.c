#include<stdio.h>

#define N 100
#define INF 10000000

#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
int G[N+1][N+1];
int color[N+1];
int d[N+1];
int Q[N+1];
int a=0,b=0;

void enqueue(int s){
  Q[b] = s;
  b++;
}

int dequeue(){
  a++;
  return Q[a-1];
}

int empty(){
  if(a==b) return 1;
  else return 0;
}

void bfs(int s){
  int i,u;

  for(i=1;i<=n;i++){    
    color[i] = WHITE;
    d[i] = -1;
  }
  color[s] = GRAY;
  d[s] = 0;
  //Q = empty;
  enqueue(s);

  while(empty()!=1){
    u = dequeue();
    for(i=1;i<=n;i++){
      if(color[i]==WHITE && G[u][i]==1){
	enqueue(i);
	color[i] = GRAY;
	d[i] = d[u] + 1;
      }
    }
    color[u] = BLACK;
  }
}

int main(){

  int i,j,k;
  int flag;

  scanf("%d",&n);

  int Adj[n+1][n+2];

  for(i=1;i<=n;i++){
    scanf("%d",&Adj[i][0]);
    scanf("%d",&Adj[i][1]);
    for(j=0;j<Adj[i][1];j++){
      scanf("%d",&Adj[i][j+2]);
    }
  }

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      G[i][j]=0;
      for(k=0;k<Adj[i][1];k++){
	if(j==Adj[i][k+2]){
	  G[i][j]=1;
	  break;
	}
      }
    }
  }

  bfs(1);

  for(i=1;i<=n;i++){
    printf("%d %d\n",i,d[i]);
  }

  return 0;
}

