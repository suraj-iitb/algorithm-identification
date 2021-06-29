#include <stdio.h>
#include <stdlib.h>
#define N 101
 
int G[N][N];
int queue[N];
int queS=0;
int queE=0;
int breadth[N]; 
 
int dequeue(void);
void enqueue(int);
void bfs(int);
void visit(int); 
 
int main(){
  int i, j, k, l, n, adj;
 
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d%d", &l, &k);
    for(j=0; j<k; j++){
      scanf("%d", &adj);
      G[l][adj] = 1;
    }
  }
 
  bfs(n);
 
  for(i=1; i<=n; i++){
    printf("%d %d\n", i, breadth[i]);
  }
 
  return 0;
}
 
void enqueue(int data){
  queue[queE] = data;
  queE = (queE + 1)%100;
}
 
int dequeue(void){
  int tmp = queue[queS];
  queS = (queS+1)%100;
  return tmp;
}
 
void bfs(int n){
  int i;
  
  for(i=1; i<=n; i++) breadth[i]=-1;
  enqueue(1);
  breadth[1]=0;
  while(queS != queE) visit(n);
}
 
void visit(int n){
  static int qued[N];
  static int depth=0;
  int i, j, p;
  p = dequeue();
   
  qued[p] = 1;
  for(i=1; i<=n; i++){
    if(G[p][i]==1 && qued[i]==0){
      qued[i] = 1;
      breadth[i] = breadth[p]+1;
      enqueue(i);
    }
  }
}
