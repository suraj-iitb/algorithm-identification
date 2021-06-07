#include<stdio.h>
#include<limits.h>
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define TRUE 1
#define FALSE 0
/*void DFSVisit(int);
  void DFS(void);*/
void BFS(int);
int deQueue(void);
void enQueue(int);
int isEmpty(void);
int G[MAX][MAX];
int D[MAX];
int F[MAX];
int color[MAX];
int Q[MAX];
int n;
int time;
int head = 0, tail = 0;
main(){
  int i, j, m, k, value, start = 1;
  scanf("%d",&n);

  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){

      G[i][j] = 0;

    }
  }

  for(i = 1; i <= n; i++){

    scanf("%d %d", &k, &m);

    for(j = 1; j <= m; j++){

      scanf("%d",&value);

      G[i][value] = 1;
    }
  }
 
  BFS(start);

  for(i = 1; i <= n; i++)
    {
      if(D[i]==INT_MAX)D[i] = -1;
      printf("%d %d\n", i, D[i]);
    }

 return 0;

}




/*void DFS(void){
  int u;

  for( u = 1; u <= n; u++ ){

    color[u] = WHITE;

  }

  time = 0;

 for( u = 1; u <= n; u++ ){
   if( color[u] == WHITE )
     DFSVisit(u);

  }

}

void DFSVisit(int u){
  int v;

  color[u] = GRAY;

  time++;
 
  D[u] = time;

  for(v = 1; v <= n ; v++){

    if(G[u][v] == 1 && color[v] == WHITE)
      DFSVisit(v);
  }
  color[u] = BLACK;

  F[u] = ++time;
  }*/

void BFS(int start){
  int u, v;

  for(u = 2; u <= n; u++ ){

    color[u] =  WHITE;

    D[u] = INT_MAX;

  }

  color[start] = GRAY;

  D[start] = 0;

  enQueue(start);
  while(isEmpty() != FALSE){

    u = deQueue();

    for( v = 1; v <= n; v++ ){
      if(color[v] == WHITE && G[u][v] == 1){

	color[v] = GRAY;

	D[v] = D[u] + 1;

	enQueue(v);
      }
    }
  }
}

void enQueue(int x){

  Q[tail] = x;

    if(tail == 100)tail = 0;
    
    else tail ++; 

}

int deQueue(){

  int x;

  x = Q[head];

  if(head == 100)head = 0;

  else head++;

  return x;
}


int isEmpty(){
  if(tail == head)return FALSE;

  else return TRUE;
}
