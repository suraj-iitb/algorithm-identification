#include<stdio.h>
#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF 1000000
int G[MAX+1][MAX+1],d[MAX+1];
int col[MAX+1],que[MAX+1];
int head,tail;
int n;

void enque(int i){
  que[tail] = i;
  tail = (tail + 1)%n;
}

int deque(){
  int v;
  v = que[head];
  head = (head + 1)%n;
  return v;
}

void bfs(int u){
  int v,i;
  for(i=0; i<=n; i++){
    d[i]=INF;
  }
  enque(u);
  d[u] = 0;
  while(head != tail){
    v = deque();
    for(i=0; i<=n; i++){
      if(G[v][i] == 0)continue;
      if(d[i] != INF)continue;
      d[i] = d[v] + 1;
      enque(i);
    }
  }

  for(i=0; i<n; i++){
    printf("%d ",i+1);
    if(d[i] == INF){
      printf("%d\n",-1);
    }
    else {
      printf("%d\n",d[i]);
    }
  }
  
}

int main(){
  int i,j,l,len,num,k;

  for(i=0; i<MAX+1; i++){
    for(j=0; j<MAX+1; j++){
      G[i][j]=0;
    }
  }
  //表に入れる  
  scanf("%d",&n);
  for(i=1; i<=n; i++){
    scanf("%d %d",&len,&num);
    len--;
    for(l=0; l<num; l++){
      scanf("%d",&k);
      k--;
      for(j=1; j<=n; j++)G[len][k]=1;
    }
  }
  
  bfs(0);
  
  return 0;
}

