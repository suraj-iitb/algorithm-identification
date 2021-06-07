#include<stdio.h>
#define MAX 100
#define INFTY (1 << 21)
#define White 0
#define Gray 1
#define Black 2
void bfs(void);
void enqueue(int);
int dequeue();
int isEmpty();
int n,M[MAX][MAX];
int head=0,tail=0,Q[MAX];
int main(){
  int u,k,v;
  int i,j;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      M[i][j] = 0;
    }
  }

  for(i = 0; i < n; i++){
    scanf("%d%d",&u,&k);
    for(j = 0; j < k; j++){
      scanf("%d",&v);
      M[u-1][v-1] = 1;
    }
  }
  bfs();

  return 0;
}

void bfs(){
  int color[MAX];
  int d[MAX];
  int i,v;
  for(i = 0; i < n; i++){
    color[i] = White;
    d[i] = INFTY;
  }
  color[0] = Gray;
  d[0] = 0;
  enqueue(0);

  while(!isEmpty()){
    int u;
    u = dequeue();
    for(v = 0; v < n; v++){
      if(M[u][v] && color[v] == White){
        color[v] = Gray;
        d[v] = d[u] + 1;
        enqueue(v);
      }
    }
    color[u] = Black;
  }
  for(i = 0; i < n; i++){
    printf("%d ",i+1);
    if(d[i] == INFTY) printf("-1\n");
    else printf("%d\n",d[i]);
  }
}

void enqueue(int x){
  Q[tail] = x;
  if(tail + 1 == MAX)tail = 0;
  else tail++;
}

int dequeue(){
  int x;
  x = Q[head];
  if(head + 1 == MAX) head = 0;
  else head++;
  return x;
}

 int isEmpty(){
   if(head == tail) return 1;
   else return 0;
 }
