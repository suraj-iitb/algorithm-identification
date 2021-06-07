#include<stdio.h>
#define N 102
#define INFTY 1e9

int n,M[N][N];
int d[N];

int q[N];
int head=0,tail=0;

void push(int x){
  q[tail]=x;
  tail++;
}

int pop(){
  int x=q[head];
  head++;
  return x;
}


void bfs(int s){
  int u,k,v,i,j;
  push(s);
  for(i=1;i<=n;i++) d[i]=INFTY;
  d[s]=0;
  while(head!=tail){
    u=pop();
    for(v=1;v<=n;v++){
      if(M[u][v]==0) continue;
      if(d[v]!=INFTY) continue;
      d[v]=d[u]+1;
      push(v);
    }
  }
  for(i=1;i<=n;i++) printf("%d %d\n",i,((d[i]==INFTY)? (-1):d[i]));
}

int main(){
  int u,k,v,i,j;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++) M[i][j]=0;
  }

  for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      M[u][v]=1;
    }
  }

  bfs(1);

  return 0;
}

