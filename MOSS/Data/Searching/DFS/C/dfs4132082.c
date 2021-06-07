#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
int AM[100][100];
int color[100], d[100], f[100], time;

void DFS();
void DFS_visit(int);

int main(){
  int i, j, u, k, v;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    for(j = 0 ; j < n ; j++){
      AM[i][j] = 0;
    }
  }

  for(i=0;i<n;i++)

  for(i = 0 ; i < n ; i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j = 0 ; j < k ; j++){
      scanf("%d",&v);
      v--;
      AM[u][v] = 1;
    }
  }

  DFS();

  return 0;
}

void DFS(){
  int i;
  for(i = 0 ; i < n ; i++){
    color[i] = 0;
  }

  time = 0;

  for(i = 0 ; i < n ; i++){
    if(color[i] == 0) DFS_visit(i);
  }

  for(i = 0 ; i < n ; i++){
    printf("%d %d %d\n",i+1, d[i],f[i]);
  }
}

void DFS_visit(int x){
  int i;

  color[x] = 1;
  d[x] = ++time;
  for(i = 0 ; i < n ; i++){
    if(AM[x][i] ==  0) continue;
    if(color[i] == 0){
      DFS_visit(i);
    }
  }
  color[x] = 2;
  f[x] = ++time;
}

