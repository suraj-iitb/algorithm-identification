#include<stdio.h>
#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF -1

int d[N],color[N],Q[N];
int head=0,tail=0;

void enqueue(int x,int n){
  Q[tail]=x;
  if(tail+1==n)
    tail=0;
  else tail++;
}

int dequeue(int n){
  int x;
  x=Q[head];
  if(head+1==n)
    head=0;
  else head++;
  return x;
}

void bfs(int Adj[N][N],int s,int n){
  int u,v;
  for(u=1;u<=n;u++){
    color[u]=WHITE;
    d[u]=INF;
    Q[u]=0;
  }
  color[s]=GRAY;
  d[s]=0;
  enqueue(s,n);
  while(tail!=head){
    u=dequeue(n);
    for(v=1;v<=n;v++)
      if(Adj[u][v]==1 && color[v]==WHITE){
        color[v]=GRAY;
        d[v]=d[u]+1;
        enqueue(v,n);
      }
    color[u]=BLACK;
  }
}

int main(){
  int n,i,j,Adj[N][N],u,k,v;
  scanf("%d",&n);
  for(i=0;i<N;i++){
    for(j=0;j<N;j++)
      Adj[i][j]=0;
  }

  for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      Adj[u][v]=1;
    }
  }
  bfs(Adj,1,n);

  for(i=1;i<=n;i++){
    printf("%d %d\n",i,d[i]);
  }
  return 0;
}

