#include <stdio.h>
void bfs(int);
int deque(void);
void enqueue(int);
int front(void);
int empty(void);

#define N 100
#define INF 10000000


int n;
int M[N][N];
int d[N];
int Q[N];
int head,tail;

int main(){
  int u;
  int k;
  int v;
  int i,j;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }
  head=1;
  tail=n+1;
  
  for(i=0;i<n;i++){
    scanf(" %d%d",&u,&k);
    u-=1;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v-=1;
      M[u][v]=1;
    }
  }

  bfs(0);
  return 0;
}



int deque(){
  int x=Q[head];
  head=(head+1)%N;
  return x;
}

void enqueue(int x){
  Q[tail]=x;
  tail=(tail+1)%N;
}


int front(){
  return Q[head];
}


int empty(){
  if(head==tail)return 1;
  else return 0;
}



void bfs(int s){
  int i,u,v;
  enqueue(s);
  for(i=0;i<n;i++){
    d[i]=INF;
  }
  d[s]=0;
    while(empty()!=1){
      u=front();
      deque();
      for(v=0;v<n;v++){
	if(M[u][v]==0)continue;
	if(d[v]!=INF)continue;
	d[v]=d[u]+1;
	enqueue(v);
      }
    }
    for(i=0;i<n;i++){
      printf("%d ",i+1);
      if(d[i]==INF)printf("-1\n");
      else printf("%d\n",d[i]);
    }
  }
