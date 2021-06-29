#include<stdio.h>
#define N 501

static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n,y,data[N][N],C[N],d[N],f[N];

void dfs_1(int r)
{
  int a;

  C[r]=GRAY;
  y++;
  d[r]=y;

  for(a=0;a<n;a++){
    if(data[r][a]==0){
      continue;
    }
    if(C[a]==WHITE){
      dfs_1(a);
    }
  }
  C[r]=BLACK;
  f[r]=++y;
}
void dfs_2()
{
  int i,g;
  for(i=0;i<n;i++){
    C[i]=WHITE;
  }
 y=0;
  for(g=0; g<n; g++){
    if(C[g] == WHITE){
      dfs_1(g);
    }
  }
  for(i=0; i<n; i++){
    printf("%d %d %d",i+1,d[i],f[i]);
    printf("\n");
  }
}

int main()
{
  int i,j,r,k,v;

  scanf("%d",&n);

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      data[i][j]=0;
    }
  }
  for(i=0; i<n; i++){
    scanf("%d%d",&r,&k);
    r--;
    for(j=0; j<k; j++){
      scanf("%d",&v);
      v--;
      data[r][v] = 1;
    }
  }

  dfs_2();

  return 0;
}
