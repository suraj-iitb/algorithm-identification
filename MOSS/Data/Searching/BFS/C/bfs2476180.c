#include<stdio.h>
int G[101][101];
int d[101];
int n;
int Que[1000];
int head=0, tail=0;
void enqueue(int q){
  Que[head]=q;
  head++;
}  
int dequeue(){
  tail++;
  return Que[tail-1];
} 
int size(){
  return head-tail;
}

void bfs(int i){
  int j;
  for(j=0;j<n;j++){
    if(G[i][j]==1 && d[j]==-1){
      d[j]=d[i]+1;
      enqueue(j);
    }
  }
}  
int main(){ 
  int i,j,v,k,u;
  scanf("%d",&n);
  for(i=0;i<101;i++) d[i]=-1;
  for(i=0;i<n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      G[u-1][v-1]=1;
    } 
  }
  d[0]=0;
  bfs(0);
  while(size()!=0) bfs(dequeue());
   
  for(i=0;i<n;i++) printf("%d %d\n",i+1,d[i]);
   
  return 0;
}
