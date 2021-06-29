#include <stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void DFS(void);
void DFS_visit(int);

int n, im[N][N];
int color[N],d[N], f[N], t=0;

int main()
{
  int i, j, u, k, v;
   
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      im[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      im[u-1][v-1]=1;
    }
  }
 
  DFS();

  return 0;
}
void DFS()
{
  int i;

  for(i=0;i<n;i++){
    color[i]=WHITE;
  }

  for(i=0;i<n;i++){
    if(color[i]==WHITE) DFS_visit(i);
  }

  for(i=0;i<n;i++) printf("%d %d %d\n",i+1, d[i],f[i]);

}
void DFS_visit(int a)
{
  int b;

  color[a]=GRAY;
  t++;
  d[a]=t;

  for(b=0;b<n;b++){
    if(im[a][b]==1 && color[b]==WHITE) DFS_visit(b);
  }
  color[a]=BLACK;
  t++;
  f[a]=t;
}
