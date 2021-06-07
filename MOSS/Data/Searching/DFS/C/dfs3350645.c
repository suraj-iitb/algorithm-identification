#include<stdio.h>
#define N 100
#define TIME_O 0
#define TIME_I 1
#define TIME_II 2

void search(void);
void visit(int);

int t,n;
int G[N+2][N+2],time[N+2],d[N+1],f[N+1];

int main(){
  int k,u,v,i,j;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    for(i=1;i<=n;i++){
      G[i][j]=0;
    }
  }

  for(i=1;i<=n;i++){
    scanf("%d %d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      G[u][v]=1;
    }
  }

  search();

  return 0;
  
}

void search(){

  int i;
  for(i=1;i<=n;i++){
    time[i]=TIME_O;
  }
  t=0;

  for(i=1;i<=n;i++){
    if(time[i]==TIME_O) visit(i);
  }
  
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  
}

void visit(int u){
  int v;
  time[u]=TIME_I;
  d[u]=++t;
  for(v=1;v<=n;v++){
    if(G[u][v]==0)continue;
    if(time[v]==TIME_O){
      visit(v);
    }
  }

  time[u]=TIME_II;
  f[u]=++t;
}

