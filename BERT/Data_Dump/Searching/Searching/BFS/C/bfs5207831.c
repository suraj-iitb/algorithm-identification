#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define LEN 100
#define INF 100000000
#define MAX 1000000

int Q[LEN],G[LEN][LEN];
int head,tail;
int d[LEN];
int n;
void enqueue(int x){

  Q[tail]=x;
  tail=(tail+1)%LEN;
}
int dequeue(){
  int x;
  x=Q[head];
  head =(head+1)%LEN;
  return x;
}
int enpty(){
  if(tail==head)return 1;
  else return 0;
}
void bfs(int t){
  int i,u,v;
  enqueue(t);
for(i=0;i<n;i++){
  d[i]=INF;
}
d[t]=0;
while(!enpty()){
  u=dequeue();
  for(v=0;v<n;v++){
    if(G[u][v]==0)continue;
    if(d[v]!=INF)continue;
    d[v]=d[u]+1;
    enqueue(v);
  }
}
for(i=0;i<n;i++){
  printf("%d %d\n",i+1,((d[i]==INF)? -1 : d[i]));
}
}
int main(){
int k,u,v,i,j,lsa;
scanf("%d",&n);
for(i=0;i<n;i++){
  for(j=0;j<n;j++){
    G[i][j]=0;
  }
}
for(i=0;i<n;i++){
  scanf("%d %d",&u,&k);
  u--;
  for(j=0;j<k;j++){
    scanf("%d",&v);
    v--;
    G[u][v]=1;
  }
}
bfs(0);
  return 0;

}

