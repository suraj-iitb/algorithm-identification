#include <stdio.h>

int n;
int Q[105];
int head = 0;
int tail = 0;
int d[101];
int G[101][101],color[101];

void enqueue(int a){
  Q[tail]=a;
  tail++;
}

int dequeue(){
  int a;
  a = Q[head];
  head++;
  return a;
}

/*void visit(u){
  int i;
  G[u].color = 1;
  d[u] = ++time;
  for(i=0;i<G[u].k;i++){
    if(G[G[u].next[i]].color == 0)
      visit(G[u].next[i]);
  }
  G[u].color = 2;
  f[u] = ++time;
  }*/

void bfs(int s){
  int i,u,v;
  for(i=1;i<=n;i++){
    color[i] = 0;
    d[i] = -1;
  }
  color[s] = 1;
  d[s] = 0;
  enqueue(s);
  while(tail != head){
    u = dequeue();
    //printf("%d\n",u);
    for(v = 1;v <= n;v++){
      if(color[v] == 0 && G[u][v] == 1){
	color[v] = 1;
	d[v]  = d[u] + 1;
	//	printf("%d:%d\n",j,d[j]);
	enqueue(v);
      }
    }
    color[u] = 2;
  }
}

int main(){
  int i,j,a,k,v;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d%d",&a,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      G[a][v] = 1;
    }
    //for(j=1;j<=n;j++)
    //  printf("%d:%d\n",G[i].id,G[i].next[j]);
  }
  bfs(1);
  for(i=1;i<=n;i++){
    printf("%d %d\n",i,d[i]);
  }

  return 0;
}

