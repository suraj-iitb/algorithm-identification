#include<stdio.h>
#define white 0
#define gray 1
#define black 2

typedef struct{
  int data[100];
  int head;
  int tail;
}queue;

queue Q;

int n,d[100] = {10000000};
int g[100][100] = {0};
int color[100] = {white};

void bfs(int);
void enqueue(int);
int dequeue(void);

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      g[u-1][v-1] = 1;
    }
  }
  for(i=0;i<n;i++)
    d[i] = 10000000;

  bfs(0);

  for(i=0;i<n;i++){
    if(d[i] == 10000000)printf("%d %d\n",i+1,-1);
    else printf("%d %d\n",i+1,d[i]);
  }
  return 0;
}

void bfs(s){
  int v,u;

  d[s] = 0;
  color[s] = gray;
  Q.head = Q.tail = 0;
  enqueue(s);

  while(Q.tail < n){
    u = dequeue();
    if(u == 10000000)break;
    for(v=0;v<n;v++){
      if(g[u][v] == 0)continue;
      if(color[v] == white){
	d[v] = d[u] + 1;
	color[v] = gray;
	enqueue(v);
      }
    }
    color[u] = black;
  }
}

void enqueue(int s){

  if(Q.tail >= n)return;
  
  Q.data[Q.tail] = s;
  Q.tail++;
}

int dequeue(){
  int s;

  if(Q.head == Q.tail)return 10000000;

  s = Q.data[Q.head];
  Q.head++;

  return s;
}

