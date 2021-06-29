#include <stdio.h>

#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF (-1000)

void enqueue(int);
int dequeue();
void BFS(int);

int n;
int d[MAX];
int c[MAX];
int M[MAX][MAX];

int Q_tail=0;
int Q_head=0;
int Q[MAX];

int main(){
  int i=0,j=0;;
  int u;
  int k;
  int v;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }

  BFS(0);
  
  return 0;
}

void BFS(int s){
  int u=0;
  int v=0;
  int i=0;
  enqueue(s);
  for(i=0;i<n;i++){
    d[i]=INF;
  }
  d[s]=0;
  while(Q_tail!=Q_head){
    u=dequeue();
    for(v=0;v<n;v++){
      if(M[u][v]&&c[v]==WHITE){
	c[v]=GRAY;
	d[v]=d[u]+1;
	enqueue(v);
      }
      c[u]=BLACK;
    }
  }

  for(i=0;i<n;i++){
    printf("%d ",i+1);
    if(d[i]==INF) printf("-1\n");
    else printf("%d\n",d[i]);
  }
}

void enqueue(int s){
  Q[Q_tail]=s;
  if(Q_tail + 1 == n)
    Q_tail=0;
  else Q_tail++;
}

int dequeue(){
  int x;
  x=Q[Q_head];
  if(Q_head+1==n) Q_head=0;
  else Q_head++;
  return x;
}

