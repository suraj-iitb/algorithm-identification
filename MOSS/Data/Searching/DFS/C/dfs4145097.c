#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

int color[100];
int n,M[100][100];
int S[1000],top=0;
int open[100],close[100],time;
int nt[100];

void push(int x){
  S[++top]=x;
}

int pop(){
  top--;
  return S[top+1];
}

int empty(){
  return top==0;
}

int next(int u){
  int v;
  for(v=nt[u];v<n;v++){
    nt[u]=v+1;
    if(M[u][v])return v;
  }
  return -1;
}

void dfs_visit(int r){
  int i,u,v;
  for(i=0;i<n;i++) nt[i]=0;
  push(r);
  color[r]=GRAY;
  open[r]=++time;

  while(!empty()){
    u=S[top];
    v=next(u);
    if(v!=-1){
      if(color[v]==WHITE){
	color[v]=GRAY;
	open[v]=++time;
	push(v);
      }
    }
    else{
      pop();
      color[u]=BLACK;
      close[u]=++time;
    }
  }
}

void dfs(){
  int i;
  for(i=0;i<n;i++){
    color[i]=WHITE;
    nt[i]=0;
  }
  time=0;

  int u;

  for(u=0;u<n;u++){
    if(color[u]==WHITE) dfs_visit(u);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,open[i],close[i]);
  }
}

int main(){
  int u,k,v;
  int i,j;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++) M[i][j]=0;
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }
  dfs();
  return 0;
}

