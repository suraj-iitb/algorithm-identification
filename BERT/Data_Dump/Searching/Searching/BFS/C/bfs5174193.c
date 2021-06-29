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

queue G;

int n,d[MAX] = {INF};
int g[MAX][MAX] = {0};
int color[MAX] = {white};

void bfs(int);
void enqueue(int);
int dequeue(void);

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d %d",&u,&k);
    for(j = 0; j < k; j++){
      scanf("%d",&v);
      g[u - 1][v - 1] = 1;
    }
  }
  for(i = 0; i < n; i++)
    d[i] = INF;

  bfs(0);

  for(i = 0; i < n; i++){
    if(d[i] == INF){
        printf("%d %d\n",i + 1,-1);
     } else{

      printf("%d %d\n",i + 1,d[i]);
     }
  }
  
  return 0;
  
}

void bfs(x){
  int i,j;

  d[x] = 0;
  color[x] = gray;
  G.head = G.tail = 0;
  enqueue(x);

  while(G.tail < n){
    j = dequeue();
    if(j == INF){
        break;
    }

    for(i = 0; i < n; i++){
      if(g[j][i] == 0){
          continue;
      }
      if(color[i] == white){
	    d[i] = d[j] + 1;
	    color[i] = gray;
	    enqueue(i);
      }
    }
    color[j] = black;
  }
}

void enqueue(int x){

  if(G.tail >= n){
      return;
  }
  
  G.data[G.tail] = x;
  G.tail++;
  
}

int dequeue(){
  int x;

  if(G.head == G.tail){
      return INF;
  }

  x = G.data[G.head];
  G.head++;

  return x;
  
}


