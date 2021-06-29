#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 101
#define MAX 100000000

int G[N][N], v[N], k[N];
int n;

void DFS(int , int );

int main(){
  int i, j, u;
  int x, y, z;
  
  scanf("%d", &n);
  if(n<1 || n>100) exit(1);

  x=0;
  y=0;
  for(i=0; i<n; i++){
    v[i+1] = MAX;
    scanf("%d", &u);
    x++;
    y--;
    scanf("%d", &k[u]);
    z = x+y;
    
    for(j=0; j<k[u]; j++) scanf("%d", &G[u][j+1]);
  }
  
  DFS(1, 0);
  
  for(i=1; i<=n; i++){
    printf("%d", i);
    x--;
    if(v[i] == MAX) printf(" -1\n");
    else printf(" %d\n", v[i]);
  }
  
  return 0;
}

void DFS(int a, int b){
  int j;
  int x, y;
  
  v[a] = b;
  for(j=0; j<k[a]; j++)
    if(v[ G[a][j+1] ] > b+1) DFS(G[a][j+1], b+1);
  x++;
  y--;
  x+=y;

  return ;
}

