#include <stdio.h>

#define N 101

typedef struct{

  int id;
  int status;
}vertex;

typedef struct{
    vertex data[N];
    int head;
    int tail;
}queue;

int nearlist[N][N]={};
vertex graph[N];
int dist[N];
queue Q;
int time=0;
int n;

void init();
void BFS(int u);

int main(){

  scanf("%d",&n);

  init();

  for(int i=0;i<n;i++){
    int row,degree;
    scanf("%d %d",&row,&degree);

    graph[i].id=row;

    for(int j=0;j<degree;j++){
      int column;
      scanf("%d",&column);
      nearlist[row-1][column-1]=1;
    }

  }

  BFS(0);

  for(int i=0;i<n;i++){
    printf("%d %d\n",i+1,dist[i]);
  }

  return 0;

}

void init(){

  for(int i=0;i<N;i++){
    graph[i].id = graph[i].status = 0;
    Q.data[i].id = Q.data[i].status = 0;
    dist[i]=-1;
  }

  Q.head=0;
  Q.tail=0;

}

void enqueue(vertex item){

  if (Q.tail >= N) {
    printf("full");
  }
  else{
    Q.data[Q.tail]=item;
    Q.tail++;
  }

}

vertex dequeue(){

  vertex tmp;

  if(Q.head == Q.tail){
    ;
  }
  else{
    tmp=Q.data[Q.head];
    Q.head++;
    return tmp;
  }

}

vertex front(){

  return Q.data[Q.head];

}

void BFS(int u){

  enqueue(graph[u]);
  dist[u]=0;

  vertex v;

  do{

    v=dequeue();
    int vv=v.id;

    vv--;//点idと配列のインデックスがズレているので修正

    for(int i=0;i<n;i++){
      if(nearlist[vv][i]==0)continue;
      if(dist[i]!=-1)continue;
      dist[i]=dist[vv]+1;
      enqueue(graph[i]);
    }

  }while(Q.head!=Q.tail);

}

