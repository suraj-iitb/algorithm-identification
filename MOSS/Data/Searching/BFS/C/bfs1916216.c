#include<stdio.h>

#define MAX 101
#define WHITE -1
#define GRAY 0
#define BLACK 1
#define INF 1000000000

int n,head,tail;
int color[MAX],d[MAX],f[MAX],Q[MAX],Adj[MAX][MAX];

enqueue(int x){
  Q[tail]=x;
  if(tail+1==MAX) tail=0;
  else tail++;
}

int dequeue(){
  int x;

  x=Q[head];
  if(head+1==MAX) head=0;
  else head++;

  return x;
}

bfs(int s){
  int i,j;

  for(i=0;i<n;i++){
    color[i]=WHITE;
    d[i]=INF;
  }

  color[s]=GRAY;
  d[s]=0;
  enqueue(s);

  while(head!=tail){
    i=dequeue();
    for(j=0;j<n;j++){
      if(Adj[i][j]==1 && color[j]==WHITE){
	color[j]=GRAY;
	d[j]=d[i]+1;
	enqueue(j);
      }
    }
    color[i]=BLACK;
  }
}

int main(){
  int i,u,k,j,v;

  for(i=0;i<MAX;i++){
    for(j=0;j<MAX;j++){ 
      Adj[i][j]=0;
    }
  }

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      Adj[u-1][v-1]=1;
    }
  }

  bfs(0);

  for(i=0;i<n;i++){
    if(d[i]==INF) d[i]=-1;
  }

  for(i=0;i<n;i++){
    printf("%d %d\n",i+1,d[i]);
  }

  return 0;
}
