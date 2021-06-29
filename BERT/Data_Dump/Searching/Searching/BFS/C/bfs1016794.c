#include <stdio.h>

#define N 102
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF 999999

int n,adj[N][N],color[N],d[N],Q[N],head=1,tail=1;

int Queempty(){
  if (head==tail){
    return 1;
  } else {
    return 0;
  }
}

void Enqueue(int r){
  int i;
  Q[tail] = r;
  tail++;
}

int Dequeue(){
  int i;
  i = Q[head];
  Q[head] = -1;
  head++;
  return i;
}

void BFS(int s){
  int u,v;
  color[s]=GRAY;
  d[s]=0;
  Enqueue(s);
  while(Queempty()==0){
    u = Dequeue();
    for (v=1;v<=n;v++){
      if (color[v]==WHITE&&adj[u][v]==1){
	color[v]=GRAY;
	d[v]=d[u]+1;
	Enqueue(v);
      }
    }
    color[u]=BLACK;
  }
  
}

int main() {
  int i,j,u,k,v,s=1;
  //ini
  for (i=1;i<N;i++){
    for (j=1;j<N;j++){
      adj[i][j]=0;
    }
    Q[i]=-1;
    color[i]=WHITE;
    d[i]=INF;
  }
  //

  scanf ("%d",&n);
  for (i=1;i<=n;i++){
    scanf ("%d%d",&u,&k);
    for (j=1;j<=k;j++){
      scanf("%d",&v);
      adj[u][v]=1;
    }
  }

  BFS(s);
  for (i=1;i<=n;i++){
    if (d[i]==INF) {
      d[i]=-1;
    }
    printf("%d %d\n",i,d[i]);
  }
  return 0;
}
