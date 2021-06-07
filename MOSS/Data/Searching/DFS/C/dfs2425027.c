#include<stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs(void);
void visit(int);

int a[100][100];
int color[100];
int f[100];
int d[100];
int time;
int n;

int main(){
  int u,i,j,k,v;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      a[u-1][v-1] = 1;
    }
  }

  dfs();

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }

  return 0;
}

void dfs(){//printf("in\n");
  int i;

  for(i=0;i<n;i++) color[i] = WHITE;

  time = 0;

  for(i=0;i<n;i++){
    if(color[i] == WHITE) visit(i);
  }
}

void visit(int u){
  int i;
  
  color[u] = GRAY;
  d[u] = ++time;
  
  for(i=0;i<n;i++){
    if(a[u][i]==1){
      if(color[i]==WHITE) visit(i);
    }
  }

  color[u] = BLACK;
  f[u] = ++time;
}
