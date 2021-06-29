#include <stdio.h>
#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct {
  int u;
  int k;
  int v[N];
  int d,f;
  int color;
} mat_t;

int n,matrix[N][N],time;
mat_t arr[N];

void dfs_visit(int u){
  int v;
  arr[u].color=GRAY;
  arr[u].d=++time;
  for(v=0;v<n;v++){
    if(matrix[u][v]==0) continue;
    if(arr[v].color==WHITE) dfs_visit(v);
  }
  arr[u].color=BLACK;
  arr[u].f=++time;
}

void dfs(){
  int u;
  for(u=0;u<n;u++){
    arr[u].color=WHITE;
  }
  time=0;
  for(u=0;u<n;u++){
    if(arr[u].color==WHITE) dfs_visit(u);
  }
}

int main(){
  int i,j,k=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d%d",&arr[i].u,&arr[i].k);
    if(arr[i].k==0) continue;
    for(j=0;j<arr[i].k;j++){
      scanf("%d",&arr[i].v[j]);
    }
  }

  for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        if(arr[i].v[k]==j+1) {
          matrix[i][j]=1;
          k++;
        }
        else matrix[i][j]=0;
      }
      k=0;
    }

    dfs();
  for(i=0;i<n;i++){
    printf("%d %d %d\n",arr[i].u,arr[i].d,arr[i].f);
  }
  return 0;
}
