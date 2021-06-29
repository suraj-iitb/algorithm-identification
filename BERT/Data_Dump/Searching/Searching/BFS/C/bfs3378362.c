#include<stdio.h>
#define N 100
int n,a[N][N],b[N],c[N],d[N],t;
int Q[N*2],head,tail;

void enqueue(int x){
  Q[tail++]=x;
}
int dequeue(){
  int x;
  x=Q[head++];
  return x;
}
int empty(){
  return head==tail;
}
void bfs(int p){
  int i,u,v;
  enqueue(p);
  for(i=0;i<n;i++){
    b[i]=100000;
  }
  b[p]=0;
  while(!empty()){
    u=dequeue();
    for(v=0;v<n;v++){
      if(a[u][v]==0) continue;
      if(b[v]!=100000) continue;
      b[v]=b[u]+1;
      enqueue(v);
    }
  }
    for(i=0;i<n;i++){
    printf("%d %d\n",i+1,((b[i]==100000)?(-1):b[i]));
  }
}

int main(){
  int i,j,u,v,k;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
     for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      a[u][v]=1;

    }
  }
  bfs(0);
  return 0;
}
