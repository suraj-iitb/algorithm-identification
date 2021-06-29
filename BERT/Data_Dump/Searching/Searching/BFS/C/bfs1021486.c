#include<stdio.h>
#include<limits.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

int Q[105],Adj[105][105],d[105],n,m[105];

void Q_Empty(){
  int i;
  for(i = 0; i < n; i ++){
    Q[i]=0;
  }
}

void Q_Enqueue(int s){
  int i;  
  for(i = 0; i < n; i ++){
    if(Q[i]==0){
      Q[i] = s;
      break;
    }
  }
 
}

int Q_Dequeue(){
  int i,u;
  u = Q[0];
  for(i = 0; i < n-1; i ++){
    Q[i] = Q[i+1];
  } 
  return u;
}

void BFS(int s){
  int i,u,v,color[105];
  for(u = 1; u <= n; u ++){
    color[u] = WHITE;
    d[u] = -1;
    color[s] = GRAY;
  }
  d[s] = 0;
  Q_Empty();
  Q_Enqueue(s);
  while(Q[0] != 0){
    u = Q_Dequeue(); 
    for(i = 1; i <= m[u]; i ++){
      if(color[Adj[u][i]] == WHITE){	
	color[Adj[u][i]] = GRAY;	
	d[Adj[u][i]] = d[u] + 1;	
	Q_Enqueue(Adj[u][i]);
      }
    }
    color[u] = BLACK;
  }
  
}
int main(){ 
  int u,i,j,dust;
  scanf("%d",&n);
  for(u = 1; u <= n; u++){
    for(j = 1; j <= n; j++){
      Adj[u][j]=0;
    }
  }
  for(u = 1; u <= n; u++){
    scanf("%d%d",&dust,&m[u]);
      for(i = 1; i <= m[u]; i++){
	scanf("%d",&Adj[u][i]);
      }	
  }
  BFS(1);
  
  for(u = 1; u <= n; u++){
    printf("%d %d\n",u,d[u]);
  }
  return 0;
}
