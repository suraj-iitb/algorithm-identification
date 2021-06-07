/* 入力１

4
1 1 2
2 1 4
3 0
4 1 3

*/

/* 入力２

6
1 2 2 3
2 2 3 4
3 1 5
4 1 6
5 1 6
6 0

*/


#include<stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define N 100

int n;
int M[N][N];
int color[N];
int d[N],f[N];
int time;

void dfs(int u);
void dfs_init(void);


int main(void){
  int i,j;
  int m,u,v;

  scanf("%d",&n);
  
  for(i = 0;i < n;i++){
    scanf("%d %d",&u,&m);
    u--;
    
    for(j = 0;j < m;j++){
      scanf("%d",&v);
      v--;
      M[u][v] = 1;
    }
  }

  dfs_init();

  return 0;
}
       







void dfs_init(void){
  int u;
  
  for(u = 0;u < n;u++){
    color[u] = WHITE;
  }
  
  time = 0;
  for(u = 0;u < n;u++){
    if(color[u] == WHITE){
      dfs(u);
    }
  }
  for(u = 0;u < n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
  
}


void dfs(int u){
  int v;

  d[u] = ++time;
  color[u] = GRAY;
  
  for(v = 0;v < n;v++){
    if(M[u][v] == 0){
      continue;
    }
    if(color[v] == WHITE){
      dfs(v);
    } 
  }
  
  f[u] = ++time;
  color[u] = BLACK;
}

