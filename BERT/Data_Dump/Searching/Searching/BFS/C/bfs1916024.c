#include<stdio.h>
#include<limits.h>
#define N 101
#define WHITE 0
#define BLACK 2
#define GRAY 1

typedef struct Node{
  int num;
  int adj[N];
 
}ver;

void enqueue(int);
int dequeue();
void BFS(int);
int Isempty();

int n,D[N],color[N],Q[N],G[N][N],head=1,tail=1;
ver V[N];

int main(){

  int i,j,a,k;


  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d%d",&a,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&V[a].adj[j]);
    }
  }

  BFS(1);

  for(i=1;i<=n;i++){
    if(D[i]==INT_MAX)printf("%d -1\n",i);
    else printf("%d %d\n",i,D[i]);
  }
  return 0;
}

void BFS(int s){

  int i,u;

  for(i=s;i<=n;i++){
    color[i]=WHITE;
    D[i]=INT_MAX;
  
  }

  color[s]=GRAY;
  D[s]=0;

  enqueue(s);

  while(Isempty()){

    u=dequeue();

    for(i=1;V[u].adj[i]!=0;i++){
      if(color[V[u].adj[i]]==WHITE){
	color[V[u].adj[i]]=GRAY;
	D[V[u].adj[i]]=D[u]+1;
	enqueue(V[u].adj[i]);
      }
    }
    color[u]=BLACK;
  }
  
}

void enqueue(int x){

  Q[tail]=x;
  if(tail+1==n+1)tail=1;
  else tail++;

}

int dequeue(){

  int x;

  x=Q[head];
  Q[head]=0;
  if(head+1==n+1) head=1;
  else head++;

  return x;
}

int Isempty(){

  if( Q[head] != 0 )return 1;
  else return 0;
}
