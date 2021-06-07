#include<stdio.h>

typedef struct{
int v[100];
int k;
} Roll;

void stack(int);
int push();
void dfs();
void visit(int);

char color[101];
int top=0;
int n;
Roll A[101];
int f[101];
int d[101];
int time;
int main(){
  int i,j;
  int T;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&T);
    scanf("%d",&A[i].k);
    for(j=0;j<A[i].k;j++){
      scanf("%d",&A[i].v[j]);
    }
  }
  dfs();
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }

  
  return 0;
}

void dfs(){
  int i;
  for(i=1;i<=n;i++){
    color[i]='w';
    d[i]=0;
    f[i]=0;
  }
  time=0;
  
  for(i=1;i<=n;i++){
    if(color[i]=='w')
      visit(i);
  }
}
void visit(int u){
  int i;
  color[u]='g';
  d[u]=++time;
  for(i=0;i<A[u].k;i++){
    if(color[A[u].v[i]]=='w')
      visit(A[u].v[i]);
  }
  color[u]='b';
  f[u]=++time;
}

