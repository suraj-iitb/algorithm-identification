#include <stdio.h>

#define INF -1

typedef struct{
int v[101];
int k;
} Roll;

char color[101];
int Q[101];
int head=0;
int tail=0;
int d[101];
int n;
Roll A[101];

void enqueue(int key){
  Q[head]=key;
  head++;
  return;
}

int dequeue(){
  int x;
  x=Q[tail];
  tail++;
  return x;
}

void bfs(Roll G[],int s){
  int u,x;
  for(u=1;u<=n;u++){
    color[u]='W';
    d[u]=INF;
  }
  color[s]='G';
  d[s]=0;
  enqueue(s);
  while(head!=tail){
    u=dequeue();
    for(x=0;x<G[u].k;x++){
      if(color[G[u].v[x]]=='W'){
        color[G[u].v[x]]='G';
        d[G[u].v[x]]=d[u]+1;
        enqueue(G[u].v[x]);
      }
    }
    color[u]='B';
  }
  return;
}



int main(){
  int i,j;
  int T;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&T);
    scanf("%d",&A[i].k);
    for(j=0;j<A[i].k;j++){
      scanf("%d",&A[i].v[j]);
    }
  }
  bfs(A,1);
  for(i=1;i<=n;i++){
    printf("%d %d\n",i,d[i]);
  }
  return 0;
}

