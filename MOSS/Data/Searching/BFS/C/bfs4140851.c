#include<stdio.h>

#define MAX 101
#define INF -1
#define WHITE 1
#define GRAY 2
#define BLACK 3

typedef struct{
  int k;
  int v[MAX];
}node;

int n,tail=0,head=0;
int color[MAX],d[MAX],Q[MAX];
node G[MAX];

void bfs(int);
void enqueue(int);
int dequeue(void);

int main(){
  int i,j,u;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&u);
    scanf("%d",&G[u].k);
    for(j=0;j<G[i].k;j++) scanf("%d",&G[i].v[j]);
  }
  
  bfs(1);

  for(i=1;i<=n;i++) printf("%d %d\n",i,d[i]);
  
  return 0;
}

void bfs(int s){
  int i,u,v;

  for(i=1;i<=n;i++){
    color[i]=WHITE;
    d[i]=INF;
  }
  
  color[s]=GRAY;
  d[s]=0;
  enqueue(s);

  while(head!=tail){
    u=dequeue();
    for(i=0;i<G[u].k;i++){
      v=G[u].v[i];
      if(color[v]==WHITE){
	color[v]=GRAY;
	d[v]=d[u]+1;
	enqueue(v);
      }
    }
    color[u]=BLACK;
  }

}

void enqueue(int x){
  Q[tail]=x;

  if(tail+1==MAX) tail=0;
  else tail++;
}

int dequeue(void){
  int x;

  x=Q[head];

  if(head+1==MAX) head=0;
  else head++;

  return x;
}

