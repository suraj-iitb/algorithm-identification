#include<stdio.h>

#define WHITE 1
#define BLACK 2
#define GRAY 3
#define INF -1

#define N 101

void bfs(int);

//queue

int dequeue(void);
void enqueue(int);

int G[N][N];
int Q[N];
int color[N],d[N];

int tail=0,head=0;
int num;
int num_element=0;
int length=N;


int main(){
  int i,j;
  int k,v,u;
  int start = 1;
  

  scanf("%d",&num);
  //printf("%d\n",num);

  for(i=1;i<=num;i++){
    for(j=1;j<=num;j++){
      G[i][j] = -1;
    }
  }
  
  for(i=1;i<=num;i++){
    scanf("%d%d",&u,&k);
    //printf("%d    %d\n",u,k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      G[u][v] = 1;
    }
  }

  /*
  for(i=1;i<=num;i++){
    for(j=1;j<=num;j++){
      printf("%d ",G[i][j]);
    }
    printf("\n");
  }
  */

  bfs(start);

  

  for(i=1;i<=num;i++){
    printf("%d %d\n",i,d[i]);
  }

  return 0;

}



void bfs(int s){
  int u;
  int i,j;
  int v;
  
  //each vertex u in V - {s}
  for(i=1;i<=num;i++){
    color[i] = WHITE;
    d[i] = INF;
  }
  color[s] = GRAY;
  d[s] = 0;

  //Q = empty;
  for(i=0;i<num;i++) Q[i] = 0;
  
  enqueue(s);
  
  while(tail != head){
    
    u = dequeue();

    //each v in adj[u]
    for(v=1;v<=num;v++){
      if(G[u][v] == -1) continue;
      if(color[v] == WHITE){
	color[v] = GRAY;
	d[v] = d[u]+1;
	enqueue(v);
      }
    }

    color[u] = BLACK;

  }
}


int dequeue(void){
  int x;

  x = Q[head];
  
  if(head + 1 == length){
    head = 0;
  }

  else head = head + 1;

  num_element--;
  
  return x;
}

void enqueue(int x){
  Q[tail] = x;
  
  if(tail + 1 == length) tail = 0;

  else tail = tail + 1;

  num_element++;
}

  

