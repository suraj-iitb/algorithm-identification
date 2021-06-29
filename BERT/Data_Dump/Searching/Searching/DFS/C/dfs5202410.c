#include<stdio.h>

#define N 100
#define WHITE 0
#define BLACK 2
#define GRAY 1

int color[N],n,a[N][N];
int p[N],q[N],no;
void dfs_visit(int s){
  int t;
  color[s]=GRAY;
  p[s]=++no;
  for(t=0;t<n;t++){
    if(a[s][t]==0) continue;
    if(color[t]==WHITE) dfs_visit(t);
  }
  color[s]=BLACK;
  q[s]=++no;
}

void dfs(void){
  int i;
  for(i=0;i<n;i++){
    color[i]==WHITE;
  }
  for(i=0;i<n;i++){
    if(color[i]==WHITE) dfs_visit(i);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,p[i],q[i]);
  }
}

int main(){
  int i,j,x,y,k;
  scanf("%d",&n);
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      a[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&x,&y);
    x--;
    for(j=0;j<y;j++){
      scanf("%d",&k);
      k--;
      a[x][k]=1;
    }
  }
  dfs();
  return 0;
}

