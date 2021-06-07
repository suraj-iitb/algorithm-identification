#include<stdio.h>
#define W 0
#define G 1
#define B 2
int top=0;
int color[101];
int d[101],f[101];
int time=0,n;
int a[101][101];
int S[101];

void push(int x){
  S[++top]=x;
}

int pop(){
  return S[top--];
}

void visit(int i){
  int j,u,v;
  push(i);
  color[i]=G;
  d[i] = ++time;
  
  while(top!=0){
    v=0;
    u = S[top];

    for(j=1;j<=n;j++){
      if(a[u][j]==1){
	a[u][j]=0;
	v = j;
	break;
      }
    }
    if(v != 0){
      if(color[v] == W){
	push(v);
	color[v] = G;
	d[v] = ++time;
      }
    }
    else{
      pop();
      color[u] = B;
      f[u] = ++time;
      }
  }
}

void dfs(){
  int i;
  for(i=1;i<=n;i++) color[i] = W;
  
  for(i=1;i<=n;i++)
    if(color[i] == W) visit(i);
}

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);

  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++) a[i][j]=0;

  for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    if(k==0) continue;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      a[u][v]=1;
    }
  }

  dfs();

  for(i=1;i<=n;i++) printf("%d %d %d\n",i,d[i],f[i]);

  return 0;
}

