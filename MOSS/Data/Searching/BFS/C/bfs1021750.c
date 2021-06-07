#include <stdio.h>
#define N 130
#include <limits.h>
#define WHITE 0
#define BLACK 1
#define GRAY 2


int f[N],d[N],f[N],e[N];
int color[N];
int time,n;
int a[N],b[N],c[N];
int B[N][N];


int Q[N];
int head,tail;

void enqueue(int x){
  
  Q[tail] = x;
  
  if(tail + 1 == N){
    tail = 0;
  }
  else {
    tail = tail + 1;
  }
  
}

int dequeue(){
  
  int x;
  
  x = Q[head];
  if(head + 1 == N){
    head = 0;
  }
  else {
    head = head + 1;
  }
  return x;
  
}

main()
{
  
  
  int i,j,u;
  int A[N][N];
  
  
  
  scanf("%d",&n);
  
  for(i = 1; i <= n; i++){
    scanf("%d%d",&a[i],&b[i]);
    for(j = 1; j <= b[i]; j++){
      scanf("%d",&c[j]);
      A[a[i]][c[j]] = BLACK;
      B[a[i]][j] = c[j];
    }  
  }
  for(i = 0; i < N; i++){
    d[i] = -1;
  }
  bfs(1);
 
  return 0;
}

int bfs(int s)
{
  
  int i,j,v,u=a[s];
  
  for(i = 1; i <= n ; i++){
    color[u] = WHITE;
    d[u] = INT_MAX;
    color[s] = GRAY;
  }
  d[s] = 0;
  
  for(i =1; i <N; i++){
    Q[i] = 0;
  }
  head=1;
  tail=1;
  
  enqueue(s);
  
  for(j=1;Q[j] != 0;j++){
    u = dequeue();
    for(i = 1; i <= b[u]; i++){
      v = B[u][i];
      if(color[v] == WHITE){
	color[v] = GRAY;
	d[v] = d[u] + 1;
	enqueue(v);
      }
    }
    color[u] = BLACK;
  }
for(i = 1; i <= n; i++){
  printf("%d %d\n",i,d[i]);
 }
}
