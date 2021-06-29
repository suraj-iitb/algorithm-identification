#include<stdio.h>
#include<stdlib.h>
#define N 102
#define white 0
#define gray 1
#define black 2

int n,color[N],d[N],f[N],S[N],top=0,t=0,nt[N],a[N][N];

void push(int x){
  if(top==N){
    printf("Stack overflow!\n");
    exit(2);
  }
  S[++top]=x;
}

int pop(void){
  if(top==0){
    printf("Stack is empty!\n");
    exit(3);
  }
  top--;
  return S[top+1];
}

int next(int u){
  int v;
  for(v=nt[u];v<=n;v++){
    nt[u]=v+1;
    if(a[u][v]) return v;
  }
  return -1;
}

void dfs(int r){
  int i;
  for(i=1;i<=n;i++) nt[i]=0;

  push(r);
  color[r]=gray;
  d[r]=++t;

  while(S[top]!=0){
    int u=S[top],v=next(u);

    if(v!=-1){
    if(color[v]==white){
      color[v]=gray;
      d[v]=++t;
      push(v);
    }
    }
    else {
      pop();
      color[u]=black;
      f[u]=++t;
    }
  }
}

void dfs_init(){
  int i,u;
  for(i=1;i<=n;i++){
    color[i]=white;
  }
  t=0;

  for(u=1;u<=n;u++){
    if(color[u]==white) dfs(u);
  }
  
}

void print(){
  int i;
  for(i=1;i<=n;i++) printf("%d %d %d\n",i,d[i],f[i]);
}

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      a[i][j]=0;
    }
  }

  for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      a[u][v]=1;
    }
  }

  dfs_init();
  print();


  return 0;
}

