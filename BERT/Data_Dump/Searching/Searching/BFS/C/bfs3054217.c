#include<stdio.h>
#include<stdbool.h>
#define N 101
#define WHITE 0
#define BLACK 2
#define GRAY 1
#define INF -1

int GX[N][N],x,color[N],Q[N],d[N],head,tail;

bool isEnpty(){
  if(tail == head) true;
  else false;
}

void enqueue(int x){
  Q[tail] = x;
  if(tail+1 == N) tail = 0;
  else tail = tail +1;
}
			  
int dequeue(){
  int x;
  x = Q[head];
  if(head+1 == N) head = 0;
  else head = head +1;
  return x;
}

void bfs(int s){

  int i,j,k,v;

  for(i=1;i<=x;i++){
    if(i==s) continue;
    color[i] = WHITE;
    d[i] = INF;
  }
  color[s] = GRAY;
  d[s] = 0;

  enqueue(s);

  while(head != tail){
    k = dequeue();
    for(v=1;v<=x;v++){
      if(GX[k][v] == 1){
	if(color[v] == WHITE){
	  color[v] = GRAY;
	  d[v] = d[k]+1;
	  enqueue(v);
	}
	 color[k] = BLACK;
      }
    }
  }
}
  

int main(){

  int i,j,a,b,c,v,g;

  scanf("%d",&x);

  for(i=0;i<x;i++){
    for(j=0;j<x;j++){
      GX[i][j]=0;
    }
  }

  for(i=0;i<x;i++){
    scanf("%d",&v);
    scanf("%d",&g);
    for(j=0;j<g;j++){
      scanf("%d",&a);
      GX[v][a]=1;
    }
  }

  bfs(1);


  for(i=1;i<=x;i++){
    printf("%d %d\n",i ,d[i]);
  }
  return 0;
}

