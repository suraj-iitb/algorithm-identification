#include <stdio.h>
#include <stdlib.h>
#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2
 

int STACK[N];
int top = 0;
int n;
int TIME = 0;
int A[N][N];
int color[N];
int dis[N];
int fin[N];

void S_push(int i){
  top++;
  STACK[top] = i;
}

void S_pop(){
  top--;
 
}
int S_top(){
  return STACK[top];
}
int next (int a){
  int i;

  for(i=1;i<=n;++i){
    if(A[a][i]==1 && color[i]==WHITE) return i;
  }

  return -1;
}


void visit(int r){
  int u,v,i;

  S_push(r);
  color[r] = GRAY;
  dis[r] = ++TIME;

  while(top != 0){
    u = S_top();
    v = next(u);

    if(v != -1){
      S_push(v);
      color[v] = GRAY;
      dis[v] = ++TIME;
    }

    else {
      S_pop();
      color[u] = BLACK;
      fin[u] = ++TIME;
    }
  }
  
}

void dfs(){
  int i;

  for(i=1;i<=n;++i){
    color[i] = WHITE;
  }
  
  for(i=1;i<=n;++i){
    if(color[i] == WHITE) visit(i);
  }
  
}



int main(){
  int i,j,m,l,b;
 
  scanf("%d",&n);

  for(i=1;i<=n;++i){
    for(j=1;j<=n;++j)A[i][j]=0;
  }
  

  for(i=1;i<=n;++i){
    scanf(" %d %d",&m,&l);
     
    for(j=1;j<=l;++j){
      scanf("%d",&b);
      A[m][b] = 1;
    }
  }

  
  dfs();

  for(i=1;i<=n;++i){
    printf("%d %d %d\n",i,dis[i],fin[i]);

  }
 
  return 0;
}

