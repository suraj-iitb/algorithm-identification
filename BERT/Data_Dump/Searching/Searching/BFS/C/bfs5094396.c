#include<stdio.h>

#define MAX 100
#define INF 1000000000

void enqueue(int a);
int dequeue();
int empty();
void bfs(int s);

int n;
int d[MAX],queue[MAX];
int M[MAX+1][MAX+1];
int head=0,tail=0;

int main(void){
  int i,j,u,v,k;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }
  bfs(0);
  return 0;
}

void enqueue(int a){
  queue[tail]=a;
  if(tail+1 == MAX+1){tail=0;}
  else{tail++;}
}

int dequeue(){
  int a;
  a = queue[head];
  if(head+1 == MAX+1){head=0;}
  else{head++;}
  return a;
}

int empty(){
  if(head==tail){return 1;}
  else{return 0;}
}

void bfs(int s){
  int i,u,v;
  enqueue(s);
  for(i=0;i<n;i++){
    d[i]=INF;
  }
  d[s]=0;
  while(empty()!=1){
    u=dequeue();
    for(v=0;v<n;v++){
      if(M[u][v]==0){continue;}
      if(d[v]!=INF){continue;}
      d[v] = d[u]+1;
      enqueue(v);
    }
  }
  for(i=0;i<n;i++){
    printf("%d ",i+1);
    if(d[i]==INF){
      printf("-1\n");
      continue;
    }
    printf("%d\n",d[i]);
  }
}

