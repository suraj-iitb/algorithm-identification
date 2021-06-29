#include <stdio.h>
#define MAX 150
#define NIL -1
#define N 10000

int graph[MAX][MAX];
int d[MAX];
int n;
  
int Que[N];
int head=0, tail=0;
 
void enQue(int q){
  Que[head]=q;
  head++;
}
 
int deQue(void){
  tail++;
  return Que[tail-1];
}
 
int size(void){
  return head-tail;
}
 
 
void bfs(int i){

  int j;
  
  for( j = 0; j < n; j++){
  
    if(graph[i][j]==1 && d[j]==NIL){
      d[j]=d[i]+1;
      enQue(j);
    }
  }
}
 
int main(){

  int u,k,i,j,v;
  
  scanf("%d",&n);
  
  for(i = 0; i < MAX; i++) d[i]=NIL;
  for(i = 0; i < n; i++){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j = 0; j < k; j++){
      scanf("%d",&v);
      graph[u-1][v-1]=1;
    } 
  }
  d[0]=0;
  bfs(0);
  
  while(size() != 0){
    bfs(deQue());
  }
  
  for(i = 0; i < n; i++){
    printf("%d %d\n",i+1,d[i]);
  }
return 0;
}
