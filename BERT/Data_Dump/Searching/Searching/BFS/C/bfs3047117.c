#include <stdio.h>

int Adj[101][101],n,discover[101];
char color[101];
int Que[100],element_en,element_de;


void Bfs_initialization(){
  int i;
  for(i=1;i<=n;i++){
    discover[i]=-1;
    color[i]='w';
  }
  color[1]='g';
  discover[1]=0;
  
  element_en=0;
  element_de=0;
}

void Bfs_print(){
  int i;
  for(i=1;i<=n;i++)
    printf("%d %d\n",i,discover[i]);
}

int Empty(){
  if(element_en-element_de==0)
    return 1;
  return 0;
}

void Enqueue(int key){
  Que[element_en]=key;
  element_en++;
}

int Dequeue(){
  return Que[element_de++];
}

void Bfs_function(){
  int now,i;
  Bfs_initialization();

  Enqueue(1);
  while(Empty()!=1){
    now=Dequeue();

    i=1;
    while(i<=n){
      if(Adj[now][i]==0 || discover[i]!=-1){
	i++;
	continue;
      }
      discover[i]=discover[now]+1;
      Enqueue(i);
      color[i]='g';
      i++;
    }

    color[now]='b';
  }

  Bfs_print();
}

void Initialization(){
  int i,j;
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      Adj[i][j]=0;
}

int main(){
  int i,j,element,number,key;
  scanf("%d",&n);
  Initialization();

  for(i=0;i<n;i++){
    scanf("%d%d",&element,&number);
    for(j=0;j<number;j++){
      scanf("%d",&key);
      Adj[element][key]=1;
    }
  }

  Bfs_function();
  return 0;
}
