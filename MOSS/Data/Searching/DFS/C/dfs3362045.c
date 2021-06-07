#include<stdio.h>
#define N 100

int n,a[N][N];
int x=0,y=1,z=2;
int b[N],c[N],d[N],time;

void visit(int u){
  int v;
  b[u]=y;
  time++;
  c[u]=time;
  for(v=0;v<n;v++){
    if(a[u][v]==0) continue;
    if(b[v]==x){
      visit(v);
    }
  }
  b[u]=z;
  d[u]=++time;
}

void dfs(){
  int i,u;
  for(i=0;i<n;i++){
    b[i]=x;
  }
    time=0;
    for(u=0;u<n;u++){
      if(b[u]==x){
	visit(u);
      }
    }
    for(i=0;i<n;i++){
      printf("%d %d %d\n",i+1,c[i],d[i]);
    }
}

int main(){
  int i,j,u,k,v;
    scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      a[u][v]=1;
    }
  }
  dfs();
  return 0;
}

