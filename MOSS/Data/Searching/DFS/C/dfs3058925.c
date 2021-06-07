#include <stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

int time = 0;
int d[100] = {};
int f[100] = {};
int color[100] = {};
int array[100][100] = {};
int n;

void dfs(int,int *);
void visit(int,int *);

int main() {
  int i,j;
  int u;
  int k;
  int v;
  
  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%d %d",&u,&k);
    array[u-1][0] = u;
    array[u-1][1] = k;
    for(j=0;j<k;j++) {
      scanf(" %d",&v);
      array[u-1][j+2] = v;
    }
  }
  for(u=0;u<n;u++) {
    color[u] = WHITE;
  }
  for(i=0;i<n;i++) {
    if(color[i] == WHITE)
      dfs(i,array[i]);
  }
  for(i=0;i<n;i++) {
    printf("%d %d %d\n",array[i][0],d[i],f[i]);
  }
}

void dfs(int t,int *V) {
  int u;
  int minus = 101;
  /*
  for(u=0;u<n;u++) {
    color[u] = WHITE;
  }
  time=0;
  */
  //printf("%d\n",t);
  //for(u=0;u<n;u++) {
    if(color[t] == WHITE) {
      visit(t,V);
    }
    //}
  

}

void visit(int u,int *V) {
  int v;
  color[u] = GRAY;
  d[u] = ++time;

  //printf("%d:%d\n",V[0],V[1]);
  for(v=1;v<=V[1];v++) {
    //if(V[0] == 3) printf("%d\n",V[0]);
    if(color[V[v+1]-1] == WHITE) {
      visit(V[v+1]-1,array[V[v+1]-1]);
    }
  }
  
  color[u] = BLACK;
  
  f[u] = ++time;
} 

