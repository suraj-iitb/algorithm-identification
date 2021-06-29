#include<stdio.h>
#define N 100

int n, M[N+1][N+1];
int d[N+1];
int Q[N+1];
int head = 1, tail;

void enqueue(int x) {
  Q[tail] = x;
  if((tail +1) == N + 1) tail = 0;
  else tail++;
}

int dequeue() {
  int x;
  x = Q[head];
  if((head + 1) == N + 1) head = 0;
  else head++;
 return x;
}

int Q_empty() {
  int i;
  for(i = 0;i<N+1;i++)
  if(Q[i] != -111) return 111;
  return 0;
}

void BFS(int x) {
  int i,u,v,flag = 1,count=0;

  enqueue(x);
  for(i = 0;i<n;i++) d[i] = (1<<21);
  d[x] = 0;

  while(1) {
    if(Q_empty() == 0)break;

    for(i=count;i<N+1;i++) {
      u = dequeue();
      if(u!= -777) break;
    }
    if(u== -777)break;
    count = i;
    for(v = 0;v<n;v++) {
      if(M[u][v] == 0) continue;
      if(d[v] != (1<<21))continue;
      d[v] = d[u]+1;
      enqueue(v);
    }
  }

  for(i=0;i<n;i++){
    printf("%d",i+1);
    if(d[i]== (1<<21)) printf(" %d\n", -1 );
    else printf(" %d\n", d[i]);
  }
}

int main() {
  int i,j,u,k,v;

  for(i=0;i<N+1;i++) {
    Q[i]= -777;
  }

  scanf("%d\n", &n );
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]= 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d\n",&v );
      v--;
      M[u][v]= 1;
    }
  }
  BFS(0);
  return 0;
}
