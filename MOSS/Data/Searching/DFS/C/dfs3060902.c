#include <stdio.h>

#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void depth_init();
void depth();
void visit(int);
int t_time=0;
int n;
int d[MAX];
int f[MAX];
int c[MAX];
int M[MAX][MAX];

int main(){
  int i=0,j=0;;
  int u;
  int k;
  int v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }
  
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      M[u][v]=1;
    }
  }

  depth_init();
  depth();
  
  return 0;
}

void depth_init(){
  int i=0;
  for(i=0;i<n;i++) {
    c[i]=WHITE;
  }
  t_time=0;
}

void depth(){
  int i=0;
  for(i=0;i<n;i++){
    if(c[i]==WHITE)visit(i);
  }

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}


void visit(int u){
  int v;
  c[u]=GRAY;
  d[u]=++t_time;

  for(v=0;v<n;v++){
    if(M[u][v]==0) continue;
    if(c[v]==WHITE){
      visit(v);
    }
  }
  c[u]=BLACK;
  f[u]=++t_time;
}

