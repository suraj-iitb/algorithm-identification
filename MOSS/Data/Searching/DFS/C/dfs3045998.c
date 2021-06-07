#include<stdio.h>
#define WHITE 0
#define BLACK 1
#define GRAY -1
#define NUM 100
void dfs();
void visit(int);

int n,color[NUM+1],m[NUM+1][NUM+1],d[NUM+1],f[NUM+1],time;
int main(){
  int u,k,a,i,j;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      m[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&a);
      m[u][a]=1;
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
    color[i]=WHITE;
  }
  time = 0;
  for(i=1;i<=n;i++){
    if(color[i]==WHITE){
      visit(i);
    }
  }
}

void visit(int u){
  int j;
  color[u]=GRAY;
  d[u]=++time;
  for(j=1;j<=n;j++){
    if(m[u][j]==1){
      if(color[j]==WHITE){
	visit(j);
      }
    }
  }
  color[u]=BLACK;
  f[u]=++time;
}

