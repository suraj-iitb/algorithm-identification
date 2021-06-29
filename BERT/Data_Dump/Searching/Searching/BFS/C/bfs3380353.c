#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define INF 99999999

#define white 0
#define gray 1
#define black 2

struct q{
  
  int data[MAX];
  int head,tail,front,rear;
  
};

typedef struct q queue;

queue q;

int n;
int d[MAX];
int g[MAX][MAX];
int color[MAX];

void push(int x){

  if(q.tail >= n) return;
  
  q.data[q.tail] = x;
  q.tail++;
  
}

int pop(){
  int x;

  if(q.head == q.tail) return INF;

  x = q.data[q.head];
  q.head++;

  return x;
  
}


void bfs(s){
  int i,v,u;

  for(i=0;i<n;i++){
    
    d[i] = INF;
    
  }

  d[s] = 0;
  color[s] = gray;
  q.head = q.tail = 0;
  push(s);

  while(q.tail < n){
    u = pop();
    if(u == INF) break;
    for(v=0;v<n;v++){
      if(g[u][v] == 0) continue;
      if(color[v] == white){
	d[v] = d[u] + 1;
	color[v] = gray;
	push(v);
      }
    }
    color[u] = black;
  }
  
}

void print(int n, int d[]){

  int i;
  
  for(i=0;i<n;i++){
    if(d[i] == INF)printf("%d %d\n",i+1,-1);
    else printf("%d %d\n",i+1,d[i]);
  }

}
 

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
  
  bfs(0);

  print(n,d);
  
  return 0;
  
}

