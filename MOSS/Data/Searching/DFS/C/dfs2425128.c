#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NUM 100

int M[NUM][NUM],color[NUM],d[NUM],f[NUM],time,n;

void visit(int u){
  int v;

  color[u] = GRAY;
  d[u] = time++;

  for(v = 0; v < n; v++){
    if(M[u][v] == 0)
       continue;
    
    if(color[v] == WHITE)
      visit(v);
  }

  color[u] = BLACK;
  f[u] = time++;
}

void dfs(){
  int u;

  for(u = 0; u < n; u++)
    color[u] = WHITE;

  time = 0;

  for(u = 0; u < n; u++){
    if(color[u] == WHITE)
      visit(u);
  }

   for(u = 0; u < n; u++)
    printf("%d %d %d\n", u+1, d[u]+1, f[u]+1);
}

int main(){
  
  int a,i,j,k,v;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      M[i][j] = 0;
    
    }
  }

  for(i = 0; i < n; i++){
    scanf("%d",&a);
    scanf("%d",&k);

    for(j = 0; j < k; j++){
      scanf("%d",&v);
      M[a-1][v-1] = 1;
    }
  }

  dfs();

 

  return 0;
}
