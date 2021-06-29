#include<stdio.h>
#define MAX 100
#define WHITE  0
#define GRAY  1
#define BLACK  2

void DFS(int);
void DFS_init();

int n, G[MAX][MAX];
int color[MAX],X[MAX],Y[MAX], count;

int main(){
  int a,b,c,i,j;

  scanf("%d", &n);

  for ( i = 0; i<n; i++ ){
    for ( j = 0; j <n; j++ ){
      G[i][j]=0;
  }
  }
  for ( i = 0; i < n; i++ ){
    scanf("%d%d", &a, &b);
    a--;
    for ( j = 0; j < b; j++ ){
      scanf("%d", &c);
      c--;
      G[a][c]=1;
    }
  }
  
  DFS_init();
   for ( i = 0; i < n; i++ ){
    printf("%d %d %d\n", i+1, X[i], Y[i]);
  }
  return 0;
}

void DFS(int u){
  int i;
  color[u]=GRAY;
  count++;
  X[u]=count;
  for (i=0;i<n;i++){
    if (G[u][i]==0)continue;
    if(color[i]==WHITE){
      DFS(i);
    }
  }
  color[u]=BLACK;
  count++;
  Y[u] =count;
}

void DFS_init(){
  int  i;
  for (i=0;i<n;i++){
    color[i]=WHITE;
  }
  count=0;
   for (i=0;i<n;i++){
     if(color[i]==WHITE){
      DFS(i);
     }
   }
}

