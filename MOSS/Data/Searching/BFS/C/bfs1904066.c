#include <stdio.h>
#define N 100
int G[N][N],d[N],n,t,Q[N],head,tail;

void BFS(void);
void enqueue(int);
int dequeue(void);

int main (){
  int i,j,k,u,v;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    d[i] = -1;
    for(j=0;j<n;j++){
      G[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      G[u-1][v-1] = 1;
    }
  }

  BFS();

  for(i=0;i<n;i++){
    printf("%d %d\n",i+1,d[i]);
  }
  return 0;
}

void BFS(void){
  int v,i;
  d[0] = 0;
  head = 0;
  tail = 0;
  enqueue(0);

  while(head != tail){
    v = dequeue();
    for(i=0;i<n;i++){
      if(G[v][i] && d[i] == -1){
        d[i] = d[v]+1;
        enqueue(i);
      }
    }
  }
  return;
}

void enqueue(int n){
  Q[tail] = n;
  tail++;
  if(tail==N) tail=1;
}
int dequeue(){
  int n;
  n = Q[head];
  head++;
  if(head==N) head=1;
  return n;
}
