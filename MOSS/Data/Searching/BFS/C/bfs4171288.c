#include <stdio.h>
#define N 101
#define INF -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,M[N][N];
int Q[N],color[N],d[N],head,tail;

void enqueue(int x){
  Q[tail]=x;
  tail=(tail+1)%101;
}

int dequeue(void){
  int a;
  a=head;
  head=(head+1)%101;
  return Q[a];
}

void bfs(int s){
  int u,v,i;
  d[s]=0;
  color[s]=GRAY;
  enqueue(s);
  
  while(head!=tail){
    u=dequeue();
    for(v=1;v<=n;v++){
      if(M[u][v]==1 && color[v]==WHITE){
	color[v]=GRAY;
	d[v]=d[u]+1;
	enqueue(v);
      }
    }
    color[u]=BLACK;
  }
}

int main(){
  int u,v,k,i,j;
  
  scanf("%d",&n);

  for(i=1;i<=n;i++){
    d[i]=INF;
    color[i]=WHITE;
    for(j=1;j<=n;j++){
      M[i][j]=0;
    }
  }
  
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      M[u][v]=1;
    }
  }
  
  bfs(1);
  
  for(i=1;i<=n;i++){
    printf("%d %d\n",i,d[i]);
  }
  return 0;
}

