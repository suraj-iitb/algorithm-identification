#include<stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

int color[100],d[100],f[100],m[100][100],n,top=0,S[100],t=0,nt[100];

void push(int u){
  top++;
  S[top]=u;
}
int next(int u){
  int i;
  for(i=nt[u];i<n;i++){
    nt[u]=i+1;
    if(m[u][i]) return i;
  }
  return -1;
}

void dfs_visit(int r){
  int i,u,v;
  for(i=0;i<n;i++) nt[i]=0;
  push(r);
  color[r]=GRAY;
  d[r]=++t;
  while(top!=0){
    u=S[top];
    v=next(u);
    if(v!=-1){
      if(color[v]==WHITE){
	d[v]=++t;
	color[v]=GRAY;
	push(v);
      }
    }
      else{
	top--;
	color[u]=BLACK;
	f[u]=++t;
    }
  }
}

void dfs(){
  int i=0,u;
  for(i=0;i<n;i++){
    color[i]=WHITE;
    nt[i]=0;
  }
  t=0;
  for(u=0;u<n;u++){
    if(color[u]==WHITE) dfs_visit(u);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}

int main(){
  int i,j,u,k,v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++) m[i][j]=0;
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      m[u][v]=1;
    }
  }
  dfs();
  return 0;
}


