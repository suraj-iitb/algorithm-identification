#include <stdio.h>
#define MAX 100
#define INFTY 2000000000
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
int a[MAX][MAX];
int head=0,tail=0,q[MAX];

void enqueue(int t){
  q[tail]=t;
  if(t+1==MAX) tail=0;
  else tail++;
}

int dequeue(){
  int t=q[head];
  if(head+1==MAX) head=0;
  else head++;
  return t;
}

int isEmpty(){
  if(head==tail) return 1;
  else return 0;
}

void bfs(){
  int color[MAX],d[MAX],i,j;

  for(i=0;i<n;i++){
    color[i]=WHITE;
    d[i]=INFTY;

  }
  color[0]=GRAY;
  d[0]=0;
  enqueue(0);

  while(!isEmpty()){
    int u;
    u=dequeue();

    for(j=0;j<n;j++){
      if(a[u][j] && color[j]==WHITE){
        color[j]=GRAY;
        d[j]=d[u]+1;
        enqueue(j);
      }
    }
    color[u]=BLACK;
  }

  for(i=0;i<n;i++){
    printf("%d ",i+1);
    if(d[i]==INFTY) printf("-1\n");
    else printf("%d\n",d[i]);
  }
}

int main()
{
  int u,k,v,i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      a[u][v]=1;
    }
  }

  bfs();

  return 0;
}
