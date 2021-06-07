#include<stdio.h>

void dfs(void);
void visit(int);

int V1[100][100];
int d[100],f[100];
int n,k,time;
int vertex[100];

int main(){
  int i,j,a,b;

  scanf("%d",&n);
  
  for(i=0;i<n;i++){  /*初期化*/
    for(j=0;j<n;j++){
      V1[i][j] = 0;
    }
  }
  
  for(i=0;i<n;i++){ /*隣接リスト*/
    scanf("%d %d",&b,&k);
    for(j=0;j<k;j++){
      scanf("%d",&a);
      V1[i][a-1] = 1;
    }
  }
  
  dfs();
  
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  } 
  return 0;
}

void dfs(void){
  int i;
  
  for(i=0;i<n;i++)vertex[i] = 0;
  time = 0;
  for(i=0;i<n;i++){
    if(vertex[i] == 0)visit(i);
  }
}

void visit(int u){
  int i;
  
  vertex[u] = 1;
  d[u] = ++time;
  for(i=0;i<n;i++){
    if(V1[u][i] == 1 && vertex[i] == 0)visit(i);
  }
  vertex[u] = 2;
  f[u] = ++time;
}

