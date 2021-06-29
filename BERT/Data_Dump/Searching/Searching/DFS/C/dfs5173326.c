#include<stdio.h>

#define max 100
#define white 0
#define gray 1
#define black 2;

void dfs();
void visit(int);

int num,array[max][max];
int color[max],data[max],f[max],count;

int main(){
  int u,v,k,i,j;
  scanf("%d",&num);

  for(i = 0;i < num;i++){
    for(j = 0;j < num;j++){
      array[i][j] = 0;
    }
  }

  for(i = 0;i < num;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j = 0;j < k;j++){
      scanf("%d",&v);
      v--;
      array[u][v] = 1;
    }
  }
  dfs();
  return 0;
}

void visit(int u){
  int v;
  color[u] = gray;
  data[u] = ++count;
  for(v = 0;v < num;v++){
    if(array[u][v] == 0){
      continue;
    }
    if(color[v] == white){
      visit(v);
    }
  }
  color[u] = black;
  f[u] = ++count;
}

void dfs(){
  int u;
  for(u = 0;u < num;u++){
    color[u] = white;
  }
  count = 0;

  for(u = 0;u < num;u++){
    if(color[u] == white){
      visit(u);
    }
  }
  for(u = 0;u < num;u++){
    printf("%d %d %d\n",u + 1,data[u],f[u]);
  }
}

