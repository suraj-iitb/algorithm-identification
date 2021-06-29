#include <stdio.h>
#define INF -1
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX 100000
int n,Q[100],num[100][100];
int color[100],d[100],f[100],tail=0,head=0;

void enqueue(int x){
  Q[tail]=x;
  if(tail+1==MAX) tail=0;
  else tail++;
}

int dequeue(){
  int x;
  x=Q[head];
  if((head+1)==MAX)  head=0;
  else head++;
  return x;
}


int main(){
  int i,j,u,k,v;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++) num[i][j]=0;
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      num[u][v]=1;
    }
  }
  bfs(0);
  return 0;
}

void bfs(int y){
  int i,u,v;
  for(u=0;u<n;u++){
    color[i] = WHITE;
    d[u] = INF;
  }
  color[y] = GRAY;
  d[y]=0;
  enqueue(y);

  while (head != tail){
    u=dequeue();
    for(v=0;v<n;v++){
      if(num[u][v]==1){
        if( color[v]==WHITE){
          color[v]=GRAY;
          d[v]=d[u]+1;
          enqueue(v);
        }
      }
    }
    color[u]=BLACK;
  }
  for(i=0;i<n;i++){
    printf("%d %d\n",i+1,d[i]);
  }
}

