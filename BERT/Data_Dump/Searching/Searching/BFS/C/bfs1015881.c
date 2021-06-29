#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define WHITE 0
#define BRACK 1
#define GRAY 2
#define N 101

int color[N];
int d[N];
int f[N];
int e[N];
int time;
int A[N][N];
int v[N];
int B[N][N];
int n;
int Q[N];
int head, tail;

void enqueue(int x){
  Q[tail]=x;
  if(tail+1==N) tail=0;
  else tail=tail+1;
}

int dequeue(){
  int x;
  x=Q[head];
  if(head+1==N) head=0;
  else head=head+1;
  return x;
}

void BFS(int s){
  int i,u=v[s],v,j,k;

  for(i=1;i<=n;i++){
    color[u]=WHITE;
    d[u]=INT_MAX;
    color[s]=GRAY;
  }
  d[s]=0;
  
  for(i=0;i<N;i++)Q[i]=0;
  head=1;
  tail=1;
  enqueue(s);
  
  for(j=1;Q[j]!=0;j++){
    u=dequeue();
    for(i=1;i<=e[u];i++){
      v=B[u][i];
      if(color[v]==WHITE){
	color[v]=GRAY;
	d[v]=d[u]+1;
	enqueue(v);
      }
    }
    color[u]=BRACK;
  }

  for(k=1;k<=n;k++) printf("%d %d\n",k,d[k]);

}

main(){
  int i,j,v1;
  
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      A[i][j]=WHITE;
    }
  }

  scanf("%d",&n);
  
  for(i=1;i<=n;i++){
    scanf("%d%d",&v[i],&e[i]);
    for(j=1;j<=e[i];j++){
      scanf("%d",&v1);
      B[i][j]=v1;
      A[i][v1]= BRACK;
    }
  }

  for(i=0;i<N;i++)d[i]=-1;

  BFS(1);

  return 0;
}
