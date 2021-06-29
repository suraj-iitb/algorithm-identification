#include <stdio.h>
typedef struct ver{
  int e[101];
  int se;
  int color;
} ver;
  
int n,u,v;
int h,t;
int Q[500];
int d[101];
ver g[101];

int dequeue(){
  int x;
  x=Q[h];
  h++;
  return x;
}

void enqueue(int x){
  Q[t]=x;
  t++;
}

void bfs(int s){
  int u,v,i;
  for(u=1;u<=n;u++){
    g[u].color=0;
    d[u]=-1;
  }
  g[s].color=1;
  d[s]=0;
  h=t=0;
  enqueue(s);
  while(h-t!=0){
    u=dequeue();
    for(i=1;i<=g[u].se;i++){
      v=g[u].e[i];
      if(g[v].color==0){
	g[v].color=1;
	d[v]=d[u]+1;
	enqueue(v);
      }
    }
  }
  g[u].color=2;
}

int main(){
  int i,j,k,v;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    g[u].se=k;
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      g[u].e[j]=v;
    }
  }
  bfs(1);
  for(i=1;i<=n;i++){
    printf("%d %d\n",i,d[i]);
  }
 return 0;
}
