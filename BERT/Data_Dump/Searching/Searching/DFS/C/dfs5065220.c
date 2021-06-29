#include <stdio.h>

#define N 101

typedef struct{

  int id;
  int status;
  int findtime;
  int completetime;

}vertex;

int nearlist[N][N]={};
vertex graph[N];
int time=0;
int n;

void init();
void DFS(int u);

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

  for(int i=0;i<n;i++){
    if(graph[i].status==0)DFS(i);
  }

  for(int i=0;i<n;i++)printf("%d %d %d\n",i+1, graph[i].findtime , graph[i].completetime);

  return 0;

}

void init(){

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      graph[i].id = graph[i].status = graph[i].findtime = graph[i].completetime = 0;
    }
  }

}

void DFS(int u){

  time++;
  graph[u].status=1;
  graph[u].findtime=time;

  for(int v=0;v<n;v++){

    if(nearlist[u][v]==0){
      continue;
    }

    if(graph[v].status==0){
      DFS(v);
    }

  }

  graph[u].status=2;
  time++;
  graph[u].completetime=time;

}

