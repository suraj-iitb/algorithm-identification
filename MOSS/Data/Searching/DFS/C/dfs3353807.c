#include<stdio.h>

#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int G[MAX][MAX],d[MAX],f[MAX],color[MAX],time,n,S[MAX],top;

int next(int x){
  int i;
  for(i=1;i<=n;i++){
	if(G[x][i]==1 && color[i]==WHITE)return i;
  }
  return 0;
}

void push(int x){
  S[top++]=x;
}

int  pop(){
  return S[top--];
}

void visit(int r){
  int i;
  push(r);
  color[r]=GRAY;
  d[r]=++time;

  while(top!=0){
	int u=S[top-1],v;
	v=next(u);
	if(v!=0){
  	if(color[v]==WHITE){
    push(v);
    color[v]=GRAY;
    d[v]=++time;
  	}
	}
	else {
  	pop();
  	color[u]=BLACK;
  	f[u]=++time;
	}
  }
}


void dfs(){
  int i;
  for(i=1;i<=n;i++){
	if(color[i]==WHITE)visit(i);
  }
}


int main(){
  int i,j,k,u;
  scanf("%d",&n);

  for(i=0;i<n;i++){
	scanf("%d %d",&u,&k);
	for(j=0;j<k;j++){
  	int v;
  	scanf("%d",&v);
  	G[u][v]=1;
	}
  }
  dfs();
  for(i=1;i<=n;i++){
	printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}

