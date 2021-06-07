#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define W 0
#define G 1
#define B 2

void dfs(void);
void dfs_visit(int);
int next(int);
void push(int);
int pop(void);

int n,M[MAX][MAX];
int color[MAX],d[MAX],f[MAX],tt;
int nt[MAX],stack[MAX];
int top=0;

int main(){
  int u,k,v,i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
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
void dfs(){
  int i,u;
  for(i=0;i<n;i++){
    color[i]=W;
    nt[i]=0;
  }
  tt=0;
  for(u=0;u<n;u++){
    if(color[u]==W){
      dfs_visit(u);
    }
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}

void dfs_visit(int r){
  int i,u,v,h;
  for(i=0;i<n;i++){
    nt[i]=0;
  }
  push(r);
  color[r]=G;
  d[r]=++tt;
  while(top!=0){
    u=stack[top-1];
    v=next(u);
    if(v!=-1){
      if(color[v]==W){
	color[v]=G;
	d[v]=++tt;
	push(v);
      }
    }
    else{
      h=pop();
      color[u]=B;
      f[u]=++tt;
    }
  }
  
}

int next(int u){
  int v;
  for(v=nt[u];v<n;v++){
    nt[u]=v+1;
    if(M[u][v]==1){
      return v;
    }
  }
  return -1;
}

void push(int num){
  if(top==MAX){
    printf("error!!\n");
    exit(1);
  }
  stack[top]=num;
  top++;
}

int pop(void){
  if(top==0){
    printf("error!!\n");
    return -1;
  }
  top--;
  return stack[top];
}

