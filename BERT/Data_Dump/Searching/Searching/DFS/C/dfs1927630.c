#include<stdio.h>

#define MAX 101
#define GRAY -3
#define WHITE -2
#define BLACK -1
 
int temp[MAX],d[MAX],f[MAX];
int time,N;
int A[MAX][MAX];
 
void DFS();
 
void DFSvisit(int u){
  int v;
 
  temp[u] = GRAY;
  time++;
  d[u]=time;
 
  for(v=1;v<=N;v++){
    if(A[u][v]==0){
      continue;
    }
    if(temp[v]==WHITE){
      DFSvisit(v);
    }
  }  
   
  temp[u] = BLACK;
  f[u] = ++time;
}
 
void DFS(){
  int i;
  for(i=1;i<=N;i++){
    temp[i] = WHITE;
  }
 
  time=0;
 
  for(i=1;i<=N;i++){
    if(temp[i]==WHITE){
      DFSvisit(i);
    }
  }
}
 
int main (){
 
  int i,j,k,n,u;
 
  for(i=1;i<101;i++){
    for(j=1;j<101;j++){
      A[i][j] = 0;
    }
  }
 
  scanf("%d",&N);
 
  for(i=1;i<=N;i++){ 
    scanf("%d %d",&n,&k); 
    for(j=1;j<=k;j++){
      scanf("%d",&u);
      A[n][u] = 1;
    }
  }
 
  DFS();
   for(i=1;i<=N;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
 
  return 0;
}
