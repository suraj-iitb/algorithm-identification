#include<stdio.h>

int V[150][150],d[150],f[150],color[150],Q[150];
int time, n,head,tail;

void enqueue(int x){
  Q[tail] = x;
  tail++;
}

int dequeue(){
  int x = Q[head];
  head++;

  return x;
}

BFS(int s){
  int u,v;

  for(u = 1; u <= n; u++){
    color[u] = 0;
    d[u] = -1;
  }

  color[s] = 1;
  d[s] = 0;
  enqueue(s);

  while(head != tail){
    u = dequeue();
    for(v = 1; v <= n; v++){
      if(color[v] == 0 && V[u][v] == 1){
	color[v] = 1;
	d[v] = d[u] + 1;
	enqueue(v);
      }
    }
    color[u] = 2;
  }
}

int main(){
  int i,j,v,m,k,s=1;

  scanf("%d",&n);

  for(i = 1; i <= n; i++){
    scanf("%d%d",&v,&m);
    for(j = 1; j <= m; j++){
      scanf("%d",&k);
      V[v][k] = 1;
    }
  }

  BFS(s);

  for(i = 1; i <= n; i++){
    printf("%d %d\n",i,d[i]);
  }

  return 0;
}
