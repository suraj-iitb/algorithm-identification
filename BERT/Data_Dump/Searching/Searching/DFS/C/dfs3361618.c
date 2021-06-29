#include<stdio.h>
#define W 0
#define G 1
#define B 2
int n,color[100],next[100],count=0,v[100][100];
int d[100],f[100],s[100],top=0;

int nextf(int a){
  int i;
  for(i=next[a];i<n;i++){
    next[a]=i+1;
    if(v[a][i]==1)return i;
  }
  return -1;
}

void push(int a){
  top++;
  s[top]=a;
}

int pop(){
  top--;
  return s[top+1];
}

void dfsv(int r){
  int i;
  for(i=0;i<n;i++)next[i]=0;

  push(r);
  color[r]=G;
  d[r]=++count;

  while(top!=0){
    int u,v;
    u=s[top];
    v=nextf(u);
      if(v!=-1){
	if(color[v]==W){
	color[v]=G;
	d[v]=++count;
	push(v);
      }
  }
      else {
	pop();
	color[u]=B;
	f[u]=++count;
      }
  }
}

void dfs(){
  int i;
  for(i=0;i<n;i++){
    color[i]=W;
    next[i]=0;
  }

  for(i=0;i<n;i++)if(color[i]==W)dfsv(i);

  for(i=0;i<n;i++)printf("%d %d %d\n",i+1,d[i],f[i]);
}

int main(){
  int a,i,j,k,u;

  scanf("%d",&n);

  for(i=0;i<n;i++)for(j=0;j<n;j++)v[i][j]=0;
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&a);
      a--;
      v[u][a]=1;
    }
  }

  dfs();
  
  return 0;
}

