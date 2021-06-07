#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
#define INF 10000000



int Q[N];
int n,a[N][N];
int dt[N];
int head=0,tail=0;

void enqueue(int);
int dequeue();
void bfs(int);



int main(){
  int m,i,j,k,u;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&m);
      m--;
      a[u][m]=1;
    }
  }
  bfs(0);

  return 0;
}



void enqueue(int x){
  Q[tail] = x;
  tail = (tail + 1) % N;
}

int dequeue(){
  int x = Q[head];
  head = (head + 1) % N;
  return x;
}


void bfs(int s){
  int i,v,u;
  enqueue(s);
  
  for(i=0;i<n;i++) dt[i]=INF;
  dt[s]=0;
  while(head != tail){
    u = dequeue();
    for(v=0;v<n;v++){
      if(a[u][v]==0) continue;
      if(dt[v]!=INF) continue;
      dt[v]=dt[u] +1;
      enqueue(v);
    }
  }
  for(i=0;i<n;i++){
    printf("%d ",i+1);
    if(dt[i]==INF) printf("-1");
    else printf("%d",dt[i]);
    printf("\n");
  }


}

