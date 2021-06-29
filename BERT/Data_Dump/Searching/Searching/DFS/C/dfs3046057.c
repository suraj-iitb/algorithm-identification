//Depth First Search
#include <stdio.h>
int Adj[101][101],n,discover[101],finish[101],time;
char color[101];//'w'->white  'g'->gray  'b'->brack

void Dfs_initialization(){
  int i;
  for(i=1;i<=n;i++)
    color[i]='w';
  time=0;
}

void Dfs_search(int element){
  int i=1;
  color[element]='g';
  discover[element]=++time;

  while(i<=n){
    if(Adj[element][i]==0){
      i++;
      continue;
    }
    if(color[i]=='w')
      Dfs_search(i);

    i++;
  }

  color[element]='b';
  finish[element]=++time;
}

void Dfs_print(){
  int i;
  for(i=1;i<=n;i++)
    printf("%d %d %d\n",i,discover[i],finish[i]);
}

void Dfs_set(){
  int i;
  Dfs_initialization();

  for(i=1;i<=n;i++)
    if(color[i]=='w')Dfs_search(i);

  Dfs_print();
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

  Dfs_set();

  return 0;
}

