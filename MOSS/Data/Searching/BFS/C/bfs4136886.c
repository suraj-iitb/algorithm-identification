#include<stdio.h>
#define MAX 100
#define INF 100000

int matrix[MAX][MAX];
int dis[MAX];
int color[MAX];
int n,tail,head;
int que[MAX];

void enqueue(int v) {
  
  que[tail++] = v;
  if (tail == MAX) tail = 0;
  
}

int dequeue() {
  
  int res = que[head];
  head++;
  if (head == MAX) head = 0;
  return res;
  
}

void bfs(int u){
  int i,v;
  enqueue(u);
  for(i=0; i<n; i++) dis[i] = INF;
  dis[u] = 0;
  
  while(tail != head){
    int j;
    v = dequeue();
    for(j=0; j<n; j++){
      if(matrix[v][j] == 0) continue;
      if(dis[j] != INF) continue;
      dis[j] = dis[v]+1;
      enqueue(j);
    }
  }
  
  for(i=0; i<n; i++){
    printf("%d ",i+1);
    if(dis[i] == INF) printf("%d\n",-1);
    else printf("%d\n",dis[i]);
  }
}

int main(){
  int i,j;
  
  scanf("%d",&n);
  
  tail=head=0;
  
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)
      matrix[i][j]=0;
  }
  
  for(i=0;i<n;i++){
    int u,k;
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      int peak;
      scanf("%d",&peak);
      peak--;
      matrix[u][peak]=1;
    }
  }
  
  bfs(0);
  
  return 0;
  
}


