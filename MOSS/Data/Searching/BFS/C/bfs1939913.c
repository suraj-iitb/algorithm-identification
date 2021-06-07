#include<stdio.h>
  
#define MAX 100
#define INF 100000000
#define white 0
#define gray 1
#define black 2
  
typedef struct{
  int data[MAX];
  int head;
  int tail;
}queue;
  
queue Q;
  
int n,d[MAX] = {INF};
int g[MAX][MAX] = {0};
int color[MAX] = {white};
  
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
    d[i] = INF;
  
  bfs(0);
  
  for(i=0;i<n;i++){
    if(d[i] == INF)printf("%d %d\n",i+1,-1);
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
    if(u == INF)break;
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
  
  if(Q.head == Q.tail)return INF;
  
  s = Q.data[Q.head];
  Q.head++;
  
  return s;
}
