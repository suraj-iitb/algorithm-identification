#include <stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs(void);
void visit(int);

int n;
int time;
int d[100];
int f[100];
int color[100];
int a[100][100];

int main(){
  int k,v,u;
  int i,j;
  
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      a[i][j]=0;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      a[u-1][v-1]=1;
    }
  }

  dfs();

  for(i=0;i<n;i++){
    printf("%d %d% d",i+1,d[i],f[i]);
    printf("\n");
  }
  
  return 0;
}

void dfs(void){

  int i,j;
  
  for(i=0;i<n;i++){
    color[i]=WHITE;
  }
  time=0;
  for(i=0;i<n;i++){
    if(color[i]==WHITE) visit(i);
  }
}

void visit(int r){

  int i,j;

  color[r]=GRAY;
  d[r]=++time;
  for(i=0;i<n;i++){
    if(a[r][i]==0) continue;
    if(color[i]==WHITE) visit(i);
  }
  color[r]=BLACK;
  f[r]=++time;
  
}
