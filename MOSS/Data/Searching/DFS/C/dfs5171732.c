#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,time,top=0;
int s[N],color[N],nt[N],m[N][N];
int d[N],f[N];
void visit(int);

int next(int u){
  for(int v=nt[u];v<n;v++){
    nt[u]=v+1;
    if(m[u][v]) return v;
  }
  return -1;
}

void push(int r){
  top++;
  s[top]=r;
}

int pop(void){
  top--;
  return s[top+1];
}

void dfs(void){
  int u;

  for(u=0;u<n;u++){
    color[u]=WHITE;
    nt[u]=0;
  }
  time=0;
  for(u=0;u<n;u++){
    if(color[u]==WHITE){
      visit(u);
    }
  }
  for(int i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}

void visit(int r){
  int u,v;

  push(r);
  color[r]=GRAY;
  d[r]=++time;
  while(top!=0){
    u=s[top];
    v=next(u);
    if(v!=-1){
      if(color[v]==WHITE){
        push(v);
        color[v]=GRAY;
        d[v]=++time;
      }
    }else{
      pop();
      color[u]=BLACK;
      f[u]=++time;
    }
  }
}

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      m[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
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
