#include<stdio.h>
#define N 100
#define INFTY 10000000
 
int n;
int M[N][N];
int color[N], d[N], f[N];
int tt;
int Q[N*2];
int head, tail;

int empty(){
  return head==tail;
}

void bfs(int s){
  int i,u,v;
  head=tail=1;
  Q[tail++]=s;
  for(i=0;i<n;i++){
    d[i]=INFTY;
  }
  d[s]=0;
  while(!empty()){
    u=Q[head++];
    for(v=0;v<n;v++){
      if(M[u][v]==0){
	continue;
      }
      if(d[v]!=INFTY){
	continue;
      }
      d[v]=d[u]+1;
      Q[tail++]=v;
    }
  }
  for (i=0;i<n;i++){
    printf("%d %d\n", i+1,((d[i]==INFTY)?(-1):d[i]));
  }
}

int main(){
  int u,k,v,i,j; 
  scanf("%d", &n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }
  for(i=0;i<n;i++){  
    scanf("%d %d", &u, &k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }
  bfs(0);
  return 0;
}
 
