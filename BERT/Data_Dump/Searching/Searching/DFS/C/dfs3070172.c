#include<stdio.h>
#define MAX 100
void dfs(int,int);
int adj[MAX][MAX];
int d[MAX];
int f[MAX];
int flg[MAX];
int time=0;

int main(){
  int n,i,j;
  int x,y,z;
	
  scanf("%d",&n);	
  for(i=0;i<n;i++){
    flg[i]=0;
    for(j=0;j<n;j++)
      adj[i][j]=0;
  }
	
  for(i=0;i<n;i++){
    scanf("%d %d",&x,&y);
    for(j=0;j<y;j++){
      scanf("%d",&z);
      adj[x-1][z-1]=1;
    }
  }
	
  for(i=0;i<n;i++)
    if(!flg[i])
      dfs(i,n);
  for(i=0;i<n;i++)
    printf("%d %d %d\n",i+1,d[i],f[i]);
  return 0;	
}
void dfs(int u,int n){	
  flg[u]=1;
  d[u]=++time;
  for(int i=0;i<n;i++){
    if(adj[u][i] && !flg[i]){
      dfs(i,n);
    }
  }
  f[u]=++time;
  return;	
}

