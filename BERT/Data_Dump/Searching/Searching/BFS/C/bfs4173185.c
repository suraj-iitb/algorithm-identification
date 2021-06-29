#include<stdio.h>

#define MAX 101
#define INFTY -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

int M[MAX][MAX],colar[MAX],d[MAX],Q[MAX];
int head,tail,n;

void enqueue(int x){
  Q[tail]=x;
  tail++;
}

int dequeue(){
  head++;
  return Q[head-1];
}

void bfs(int s){
  int i,u,v;

  d[s]=0;
  colar[s]=GRAY;
  enqueue(s);

  while(head!=tail){
    u=dequeue();
    for(v=1;v<=n;v++){
      if((M[u][v]==1)&&(colar[v]==WHITE)){
	colar[v]=GRAY;
	d[v]=d[u]+1;
	enqueue(v);
      }
    }

    colar[u]=BLACK;
  }
}

int main(){
  int i,j,k,u,v,max=0,count=0;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    d[i]=INFTY;
    colar[i]=WHITE;
    for(j=1;j<=n;j++){
      M[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      M[u][v]=1;
    }
  }

  bfs(1);

  for(i=1;i<=n;i++){
  printf("%d %d\n",i,d[i]);
  }

  return 0;
}

